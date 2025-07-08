#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
    int profit;
} Job;

// 比较函数：按结束时间排序
int compare(const void* a, const void* b) {
    Job* jobA = (Job*)a;
    Job* jobB = (Job*)b;
    return jobA->end - jobB->end;
}

// 二分查找：找到最后一个结束时间<=target的job
int binarySearch(Job* jobs, int right, int target) {
    int left = 0;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (jobs[mid].end <= target) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int jobScheduling(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int* profit, int profitSize) {
    int n = startTimeSize;
    Job* jobs = (Job*)malloc(n * sizeof(Job));
    
    // 创建job数组
    for (int i = 0; i < n; i++) {
        jobs[i].start = startTime[i];
        jobs[i].end = endTime[i];
        jobs[i].profit = profit[i];
    }
    
    // 按结束时间排序
    qsort(jobs, n, sizeof(Job), compare);
    
    // 初始化dp数组
    int* dp = (int*)malloc(n * sizeof(int));
    dp[0] = jobs[0].profit;
    
    for (int i = 1; i < n; i++) {
        // 选择1：不选当前工作
        int profit1 = dp[i-1];
        
        // 选择2：选当前工作
        int profit2 = jobs[i].profit;
        int j = binarySearch(jobs, i-1, jobs[i].start);
        if (j != -1) {
            profit2 += dp[j];
        }
        
        // 取较大值
        dp[i] = profit1 > profit2 ? profit1 : profit2;
    }
    
    int result = dp[n-1];
    free(jobs);
    free(dp);
    return result;
}

int main() {
    int startTime[] = {1,2,3,3};
    int endTime[] = {3,4,5,6};
    int profit[] = {50,10,40,70};
    int n = sizeof(startTime)/sizeof(startTime[0]);
    
    int maxProfit = jobScheduling(startTime, n, endTime, n, profit, n);
    printf("Maximum Profit: %d\n", maxProfit); // 输出120
    
    return 0;
}
