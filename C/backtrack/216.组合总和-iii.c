/*
 * @lc app=leetcode.cn id=216 lang=c
 *
 * [216] 组合总和 III
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int **res;
int resSize;
int *resColSize;

int *temp;
int tempSize;

int accumulate(int *nums, int numsSize){
    int sum = 0;
    for (int i = 0; i < numsSize; ++i){
        sum += nums[i];
    }

    return sum;
}

void backtrack(int cur, int n, int k, int sum){
    if (tempSize + (n - cur + 1) < k || tempSize > k){
        return ;
    }

    if (tempSize == k && accumulate(temp, tempSize) == sum){
        int *tmp = malloc(sizeof(int) * tempSize);
        memcpy(tmp, temp, sizeof(int) * tempSize);
        res[resSize] = tmp;
        resColSize[resSize++] = tempSize;
        return ;
    }

    temp[tempSize++] = cur;
    backtrack(cur + 1, n, k, sum); // 选某个数
    --tempSize;
    backtrack(cur + 1, n, k, sum); // 不选某个数
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
    res = malloc(sizeof(int*) * 2001);
    temp = malloc(sizeof(int) * 2001);
    resColSize = malloc(sizeof(int) * 2001);
    resSize = tempSize = 0;
    backtrack(1, 9, k, n);
    *returnSize = resSize;
    *returnColumnSizes = resColSize;

    return res;
}
// @lc code=end

