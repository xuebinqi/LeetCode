/*
 * @lc app=leetcode.cn id=77 lang=c
 *
 * [60] 组合
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int* temp;
int tempSize;

int** ans;
int ansSize;

void dfs(int cur, int n, int k){
    if (tempSize + (n - cur + 1) < k) return;
    if (tempSize == k){
        int *tmp = malloc(sizeof(int) * k);
        memcpy(tmp, temp, sizeof(int) * k);
        ans[ansSize++] = tmp;
        return;
    }

    temp[tempSize++] = cur;
    dfs(cur + 1, n, k);
    tempSize--;
    dfs(cur + 1, n, k);
}

int **combine(int n, int k, int *returnSize, int **returnColumnSizes){
    temp = malloc(sizeof(int) * k);
    ans = malloc(sizeof(int *) * 10001);
    tempSize = ansSize = 0;
    *returnSize = 0;
    dfs(1, n, k);
    *returnSize = ansSize;
    *returnColumnSizes = malloc(sizeof(int) * ansSize);
    for (int i = 0; i < ansSize; ++i){
        (*returnColumnSizes)[i] = k;
    }

    return ans;
}
// @lc code=end