/*
 * @lc app=leetcode.cn id=40 lang=c
 *
 * [40] 组合总和 II
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int **ans;
int ansSize;
int *ansCloumnSize;

int *sequence;
int sequenceSize;

int **freq;
int freqSize;

void dfs(int pos, int target){
    if (target == 0){
        int *tmp = (int*)malloc(sizeof(int) * sequenceSize);
        memcpy(tmp, sequence, sizeof(int) * sequenceSize);
        ans[ansSize] = tmp;
        ansCloumnSize[ansSize++] = sequenceSize;
        return; 
    }

    if (pos == freqSize || target < freq[pos][0]){
        return;
    }

    dfs(pos + 1, target);

    int most = fmin(target / freq[pos][0], freq[pos][1]);
    for (int i = 1; i <= most; ++i){
        sequence[sequenceSize++] = freq[pos][0];
        dfs(pos + 1, target - i * freq[pos][0]);
    }
    sequenceSize -= most;
}

int cmp(const void *a, const void *b){
    return*(int*)a - *(int*)b;
}

int **combinationSum2(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSize){
    ans = malloc(sizeof(int*) * 2001);
    ansCloumnSize = malloc(sizeof(int) * 2001);
    sequence = malloc(sizeof(int) * 2001);
    freq = malloc(sizeof(int*) * 2001);
    ansSize = sequenceSize = freqSize= 0;
    qsort(candidates, candidatesSize, sizeof(int), cmp);

    for (int i = 0; i < candidatesSize; ++i){
        if (freqSize == 0 || candidates[i] != freq[freqSize - 1][0]){
            freq[freqSize] = malloc(sizeof(int) * 2);
            freq[freqSize][0] = candidates[i];
            freq[freqSize++][1] = 1;
        } else{
            ++freq[freqSize - 1][1];
        }
    }

    dfs(0, target);
    *returnSize = ansSize;
    *returnColumnSize = ansCloumnSize;

    return ans;
}
// @lc code=end

