/*
 * @lc app=leetcode.cn id=301 lang=c
 *
 * [301] 删除无效的括号
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char **res;
int resSize;

bool isValid(char *s){
    int cnt = 0;
    char *p = s;
    while(*p != '\0'){
        if (*p == '(') ++cnt;
        if (*p == ')') --cnt;
        if (cnt < 0) return false;

        ++p;
    }

    return cnt == 0;
}

void dfs(char *s, int sLen, int start, int leftCnt, int rightCnt) {
    if (start > sLen) return ;

    if (leftCnt == 0 && rightCnt == 0) {
        if (isValid(s)) {
            res[resSize] = malloc(sizeof(char) * (sLen + 1));
            strcpy(res[resSize], s);
            ++resSize;
        }

        return;
    }

    char subStr[sLen];
    for (int i = start; i < sLen; ++i) {
        if (i > start && s[i] == s[i - 1]){
            continue;
        }
        if (s[i] == '(' && leftCnt > 0) {
            memcpy(subStr, s, i);
            subStr[i] = '\0';
            strcat(subStr, s + i + 1);
            dfs(subStr, sLen - 1, i, leftCnt - 1, rightCnt);
        }

        if (s[i] == ')' && rightCnt > 0) {
            memcpy(subStr, s, i);
            subStr[i] = '\0';
            strcat(subStr, s + i + 1);
            dfs(subStr, sLen - 1, i, leftCnt, rightCnt - 1);
        }
    }   
}


char ** removeInvalidParentheses(char * s, int* returnSize){
    res = malloc(sizeof(char *) * 10005);
    memset(res, 0, sizeof(char *) * 10005);
    resSize = 0;

    int len = strlen(s);
    if (len == 0) {
        res[0] = "";
        *returnSize = 1;
        return res;
    }
    int leftCnt = 0, rightCnt = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '(') {
            ++leftCnt;
        } else if (s[i] == ')') {
            if (leftCnt == 0) {
                ++rightCnt;
            }
            else {
                --leftCnt;
            }
        }
    }

    dfs(s, len, 0, leftCnt, rightCnt);
    *returnSize = resSize;

    return res;
}


// @lc code=end

