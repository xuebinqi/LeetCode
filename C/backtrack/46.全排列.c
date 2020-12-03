/*
 * @lc app=leetcode.cn id=46 lang=c
 *
 * [46] 全排列
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


int **res;
int resSize;
int *resColumnSize;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void backtrack(int *nums, int numsSize, int index){
    if (index == numsSize){
        int *tmp = malloc(sizeof(int) * numsSize);
        memcpy(tmp, nums, sizeof(int) * numsSize);

        res[resSize] = tmp;
        resColumnSize[resSize++] = numsSize;
        return;
    }

    for (int i = index; i < numsSize; ++i){
        swap(&nums[i], &nums[index]);
        backtrack(nums, numsSize, index + 1);
        swap(&nums[i], &nums[index]);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    res = malloc(sizeof(int *) * 2001);
    resColumnSize = malloc(sizeof(int) * 2001);
    resSize = 0;
    int combine[2001];
    backtrack(nums, numsSize, 0);
    *returnSize =resSize;
    *returnColumnSizes = resColumnSize;
    
    return res;
}
// @lc code=end

