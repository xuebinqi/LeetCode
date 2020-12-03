/*
 * @lc app=leetcode.cn id=89 lang=c
 *
 * [89] 格雷编码
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *res;
int *visit;

void backtrack(int len, int index, int n){
    if (index == len){
        return ;
    }

    for (int i = 0; i < n; ++i){
        int tmp = 1 << i;
        int next = tmp ^ res[index - 1];
        if (visit[next]) {
            continue;
        }

        res[index] = next;
        visit[next] = 1;
        backtrack(len, index + 1, n);
    }
}

int* grayCode(int n, int* returnSize){
    if (n == 0) {
        *returnSize = 1;
        int *ans = malloc(sizeof(int) * 1);
        ans[0] = 0;
        return ans;
    }

    int len = 1 << n;
    res = malloc(sizeof(int) * len);
    res[0] = 0;
    visit = malloc(sizeof(int) * len);
    for (int i = 0; i < len; ++i){
        visit[i] = 0;
    }
    visit[0] = 1;

    backtrack(len, 1, n);

    *returnSize = len;
    return res;
}


// @lc code=end
