/*
 * @lc app=leetcode.cn id=39 lang=c
 *
 * [39] 组合总和
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int tmpCandidatesSize;
int ansSize;
int combineSize;
int *ansColunmSize;

void dfs(int * candidates, int target, int **ans, int *combine, int index){
    if (index == tmpCandidatesSize){
        return ;
    }
    if (target == 0){
        int *tmp = malloc(sizeof(int) * combineSize);
        for (int i = 0; i < combineSize; ++i){
            tmp[i] = combine[i];
        }

        ans[ansSize] = tmp;
        ansColunmSize[ansSize++] = combineSize;
        return ;
    }

    dfs(candidates, target, ans, combine, index + 1);
    if (target - candidates[index] >= 0){
        combine[combineSize++] = candidates[index];
        dfs(candidates, target - candidates[index], ans, combine, index);
        --combineSize;
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    tmpCandidatesSize = candidatesSize;
    ansSize = combineSize = 0;
    int ** ans = malloc(sizeof(int*) * 1001);
    ansColunmSize = malloc(sizeof(int) * 1001);
    int combine[2001];
    dfs(candidates, target, ans, combine, 0);
    *returnSize = ansSize;
    *returnColumnSizes = ansColunmSize;
    return ans;
}
// @lc code=end

