/*
 * @lc app=leetcode.cn id=90 lang=c
 *
 * [90] 子集 II
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

int subsetSize;

int *visit;

void backtrack(int *nums, int numsSize, int index, int *subset){
    int *tmp = malloc(sizeof(int) * subsetSize);
    memcpy(tmp, subset, sizeof(int) * subsetSize);

    res[resSize] = tmp;
    resColSize[resSize++] = subsetSize;

    for (int i = index; i < numsSize; ++i){
        if (visit[i] || (i > 0 && nums[i] == nums[i - 1] && !visit[i - 1])){
            continue;
        }
        subset[subsetSize++] = nums[i];
        visit[i] = 1;
        backtrack(nums, numsSize, i + 1, subset);
        --subsetSize;
        visit[i] = 0;
    }
}

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int n = 1 << numsSize; 
    res = malloc(sizeof(int *) * n);
    int *subset = malloc(sizeof(int) * numsSize);
    visit = malloc(sizeof(int) * numsSize);
    resColSize = malloc(sizeof(int) * n);

    memset(visit, 0, sizeof(int) * numsSize);
    resSize = subsetSize = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    backtrack(nums, numsSize, 0, subset);
    *returnSize = resSize;
    *returnColumnSizes = resColSize;

    return res;    
}


// @lc code=end
