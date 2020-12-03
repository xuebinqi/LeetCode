/*
 * @lc app=leetcode.cn id=93 lang=c
 *
 * [93] 复原IP地址
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define SEG_COUNT 4
int segments[SEG_COUNT];
char **res;
int resSize;


void backtrack(char * s, int segID, int segStart){
   //  如果找到了 4 段 IP 地址并且遍历完了字符串，那么就是一种答案
    int lenS = strlen(s);
    if (segID == SEG_COUNT){
        if (segStart == lenS){
            char * ipAddr = (char*)malloc(sizeof(char)* (lenS + 4));
            int add = 0;
            for (int i = 0; i < SEG_COUNT; ++i){
                int number = segments[i];
                if (number >= 100){
                    ipAddr[add++] = number / 100 + '0';
                }

                if (number >= 10){
                    ipAddr[add++] = number % 100 / 10 + '0';
                }
                ipAddr[add++] = number % 10 + '0';
                if (i != SEG_COUNT - 1){
                    ipAddr[add++] = '.';
                }
            }
            ipAddr[add] = 0;
            res = realloc(res, sizeof(char *) * (resSize + 1));
            res[resSize++] = ipAddr;
        }

        return;
    }

    // 如果还没有找到 4 段 IP 地址就已经遍历完了字符串，那么提前回溯
    if (segStart == lenS) {
        return ;
    }

    // 由于不能有前导零，如果当前数字为 0，那么这一段 IP 地址只能为 0
    if (s[segStart] == '0'){
        segments[segID] = 0;
        backtrack(s, segID + 1, segStart + 1);
    }

     // 一般情况，枚举每一种可能性并递归
     int addr = 0;
     for (int segEnd = segStart; segEnd < lenS; ++segEnd){
         addr = addr * 10 + (s[segEnd] - '0');
         if (addr > 0 && addr <= 0xff){
             segments[segID] = addr;
            backtrack(s, segID + 1, segEnd + 1);
         } else{
             break;
         }
     }
}

char ** restoreIpAddresses(char * s, int* returnSize){
    res = (char **)malloc(0);
    resSize = 0;
    backtrack(s, 0, 0);
    *returnSize = resSize;

    return res;
}
// @lc code=end

