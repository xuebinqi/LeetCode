/*
 * @lc app=leetcode.cn id=47 lang=c
 *
 * [47] 全排列 II
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int *visit;

void backtrack(int *nums, int numsSize, int **res, int *ansSize, int index, int *perm){
    if (index == numsSize){
        int *tmp = malloc(sizeof(int) * numsSize);
        memcpy(tmp, perm, sizeof(int) * numsSize);
        res[(*ansSize)++] = tmp;
        return ;
    }

    for (int i = 0; i < numsSize; ++i){
        if (visit[i] || (i > 0 && nums[i] == nums[i - 1] && !visit[i - 1])){
            continue;
        }

        perm[index] = nums[i];
        visit[i] = 1;
        backtrack(nums, numsSize, res, ansSize, index + 1, perm);
        visit[i] = 0;
    }
}

int cmp(const void *a , const void * b){
    return *(int*)a - *(int*)b;
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **res = malloc(sizeof(int *) * 2001);
    int *perm = malloc(sizeof(int) * 2001);
    visit = malloc(sizeof(int) * numsSize);
    memset(visit, 0, sizeof(int) * numsSize);
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    backtrack(nums, numsSize, res, returnSize, 0, perm);
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; ++i){
        (*returnColumnSizes)[i] = numsSize;
    }

    return res;
}
// @lc code=end

