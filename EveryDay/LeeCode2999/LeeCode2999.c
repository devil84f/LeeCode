/*
 * @Author: LiNing
 * @Date: 2025-04-10
 * 统计强大整数的数目
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

long long dfs(int i, bool limit_low, bool limit_high, 
    const char* low, const char* high, int limit, 
    const char* s, int pre_len, long long* memo, int n) {
// 递归边界
if (i == n) {
return 1;
}
if (!limit_low && !limit_high && memo[i] != -1) {
return memo[i];
}

int lo = limit_low ? low[i] - '0' : 0;
int hi = limit_high ? high[i] - '0' : 9;
long long res = 0;
if (i < pre_len) {
for (int digit = lo; digit <= fmin(hi, limit); digit++) {
   res += dfs(i + 1, limit_low && digit == (low[i] - '0'),
             limit_high && digit == (high[i] - '0'),
             low, high, limit, s, pre_len, memo, n);
}
} else {
int x = s[i - pre_len] - '0';
if (lo <= x && x <= fmin(hi, limit)) {
   res = dfs(i + 1, limit_low && x == (low[i] - '0'),
            limit_high && x == (high[i] - '0'),
            low, high, limit, s, pre_len, memo, n);
}
}
if (!limit_low && !limit_high) {
memo[i] = res;
}
return res;
}

long long numberOfPowerfulInt(long long start, long long finish, int limit, char* s) {
char low[32], high[32];
sprintf(low, "%lld", start);
sprintf(high, "%lld", finish);
int n = strlen(high);
char* padded_low = (char*)malloc(n + 1);

memset(padded_low, '0', sizeof(char) * n);  
sprintf(padded_low + n - strlen(low), "%s", low); // 对齐位数
int pre_len = n - strlen(s); // 前缀长度
long long* memo = (long long*)malloc(n * sizeof(long long));
for (int i = 0; i < n; i++) {
memo[i] = -1;
}
long long result = dfs(0, true, true, padded_low, high, limit, s, pre_len, memo, n);
free(padded_low);
free(memo);

return result;
}


int main() {
    printf("%lld\n", numberOfPowerfulInt(1, 6000, 4, "124")); // 示例1
    printf("%lld\n", numberOfPowerfulInt(15, 215, 6, "10"));  // 示例2
    printf("%lld\n", numberOfPowerfulInt(1000, 2000, 4, "3000")); // 示例3
    return 0;
}