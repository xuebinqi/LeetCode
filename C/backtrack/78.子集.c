/*
 * @lc app=leetcode.cn id=78 lang=c
 *
 * [78] 子集
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int **ans;
int ansSize;
int *ansColSize;

int *temp;
int tempSize;

void dfs(int cur, int *nums, int numsSize){
    if (cur == numsSize){
        int *tmp = malloc(sizeof(int) * tempSize);
        memcpy(tmp, temp, sizeof(int) * tempSize);
        ansColSize[ansSize] = tempSize;
        ans[ansSize++] = tmp;
        return;
    }

    temp[tempSize++] = nums[cur];
    dfs(cur + 1, nums, numsSize);
    tempSize--;
    dfs(cur + 1, nums, numsSize);
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    ans = malloc(sizeof(int *) * (1 << numsSize));
    ansColSize = malloc(sizeof(int) * (1 << numsSize));
    temp = malloc(sizeof(int) * numsSize);
    ansSize = tempSize = 0;
    dfs(0, nums, numsSize);
    *returnSize = 1 << numsSize;
    *returnColumnSizes = ansColSize;

    return ans;
}
// @lc code=end

