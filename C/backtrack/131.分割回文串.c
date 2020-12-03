/*
 * @lc app=leetcode.cn id=131 lang=c
 *
 * [131] 分割回文串
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

char ***res;
int resSize;
int *resColSize;
int len;

bool isPalindrome(char *s, int start, int end){
    while (start < end){
        if (s[start] != s[end]){
            return false;
        }
        ++start;
        --end;
    }

    return true;
}

void backtrack(char *s, char path[][100], int index, int mLen){
    if (index == len){
        resColSize[resSize] = mLen;
        res[resSize]  = malloc(sizeof(char**) * mLen);
        for (int i = 0; i < mLen; ++i){
            res[resSize][i] = malloc(strlen(path[i]) + 1);
            strncpy(res[resSize][i], path[i], strlen(path[i]) + 1);
        }

        ++resSize;
        return ;
    }

    for (int i = index; i < len; ++i){
        if (!isPalindrome(s, index, i)){
            continue;
        }

        strncpy(path[mLen++], s + index, i - index + 1);
        backtrack(s, path, i + 1, mLen);
        memset(path[--mLen], 0, 100);
    }
}

char *** partition(char * s, int* returnSize, int** returnColumnSizes){
    res = malloc(sizeof(char **) * 1000);
    resSize = 0;
    resColSize = malloc(sizeof(char) * 1000);
    len = strlen(s);
    char path[1000][100] = {};

    backtrack(s, path, 0, 0);

    *returnSize = resSize;
    *returnColumnSizes = resColSize;
    return res;
}


// @lc code=end

