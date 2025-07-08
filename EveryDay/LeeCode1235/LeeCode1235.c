#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
    int profit;
} Job;

// �ȽϺ�����������ʱ������
int compare(const void* a, const void* b) {
    Job* jobA = (Job*)a;
    Job* jobB = (Job*)b;
    return jobA->end - jobB->end;
}

// ���ֲ��ң��ҵ����һ������ʱ��<=target��job
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
    
    // ����job����
    for (int i = 0; i < n; i++) {
        jobs[i].start = startTime[i];
        jobs[i].end = endTime[i];
        jobs[i].profit = profit[i];
    }
    
    // ������ʱ������
    qsort(jobs, n, sizeof(Job), compare);
    
    // ��ʼ��dp����
    int* dp = (int*)malloc(n * sizeof(int));
    dp[0] = jobs[0].profit;
    
    for (int i = 1; i < n; i++) {
        // ѡ��1����ѡ��ǰ����
        int profit1 = dp[i-1];
        
        // ѡ��2��ѡ��ǰ����
        int profit2 = jobs[i].profit;
        int j = binarySearch(jobs, i-1, jobs[i].start);
        if (j != -1) {
            profit2 += dp[j];
        }
        
        // ȡ�ϴ�ֵ
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
    printf("Maximum Profit: %d\n", maxProfit); // ���120
    
    return 0;
}
