/*
 * @lc app=leetcode.cn id=17 lang=c
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char phoneMap[11][5] = {
    "\0", 
    "\0", 
    "abc\0",
    "def\0", 
    "ghi\0", 
    "jkl\0", 
    "mno\0", 
    "pqrs\0", 
    "tuv\0", 
    "wxyz\0"
};

char *digitsTmp;
int digitsSize;

char ** combinations;
int combinationsSize;

char *combination;
int combinationSize;

void backtrack(int index){
    if (index == digitsSize){
        char *tmp = malloc(sizeof(char) * (combinationSize + 1));
        memcpy(tmp, combination, sizeof(char) * (combinationSize + 1));
        combinations[combinationsSize++] = tmp;
    } else{
        char digit = digitsTmp[index];
        char *letters = phoneMap[digit - '0'];
        int len = strlen(letters);
        for (int i = 0; i < len; ++i){
            combination[combinationSize++] = letters[i];
            combination[combinationSize] = 0;
            backtrack(index + 1);
            combination[--combinationSize] = 0;
        }
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    combinationsSize = combinationSize = 0;
    digitsTmp = digits;
    digitsSize = strlen(digits);
    if (digitsSize == 0){
        *returnSize = 0;
        return combinations;
    }
    int num = 1;
    for (int i = 0; i < digitsSize; ++i) num *= 4;
    combinations = malloc(sizeof(char*) * num);
    combination = malloc(sizeof(char*) * digitsSize);
    backtrack(0);
    *returnSize = combinationsSize;
    return combinations;

}
// @lc code=end

