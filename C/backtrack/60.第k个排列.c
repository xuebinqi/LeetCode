/*
 * @lc app=leetcode.cn id=60 lang=c
 *
 * [60] 第k个排列
 */

// @lc code=start



char * getPermutation(int n, int k){
    int factorial[n];
    factorial[0] = 1;
    for (int i = 1; i < n; ++i){
        factorial[i] = factorial[i - 1] * i;
    } 
    --k;
    char *ans = malloc(sizeof(char) * (n + 1));
    ans[n] = '\0';
    int valid[n + 1];
    for (int i = 0; i <= n; ++i) {
        valid[i] = 1;
    }
    // memset(valid,  1, sizeof(int) * (n + 1));
    for(int i = 1; i <= n; ++i){
        int order = k / factorial[n - i] + 1;
        for (int j = 1; j <= n; ++j){
            order -= valid[j];
            if (!order){
                ans[i - 1] = j + '0';
                valid[j] = 0;
                break;
            }
        }

        k %= factorial[n - i];
    }

    return ans;
}
// @lc code=end