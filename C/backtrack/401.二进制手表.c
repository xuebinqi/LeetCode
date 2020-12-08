/*
 * @lc app=leetcode.cn id=401 lang=c
 *
 * [401] 二进制手表
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char **res;
int resSize;

int timeTable[10] = {8, 4, 2, 1, 32, 16, 8, 4, 2, 1};
int visited[10];

void backtrack(int num, int hour, int min, int pos){
    if (num == 0){
        if (hour > 9){
            res[resSize] = malloc(sizeof(char) * 6);
        }else{
            res[resSize] = malloc(sizeof(char) * 5);
        }

        if (min > 9){
            sprintf(res[resSize], "%d:%d", hour, min);
        } else{
            sprintf(res[resSize], "%d:0%d", hour, min);
        }

        ++resSize;
        return ;
    }

    if(hour >= 12 || min >= 60) return ;

    for (int i = pos; i < 10; ++i){
        if (visited[i]) continue;

        if (i >= 4 && min + timeTable[i] < 60){
            visited[i] = 1;
            backtrack(num - 1, hour, min + timeTable[i], i + 1);
            visited[i] = 0;
        } else if (i < 4 && hour + timeTable[i] < 12){
            visited[i] = 1;
            backtrack(num - 1, hour + timeTable[i], min, i + 1);
            visited[i] = 0;
        }
    }

}

char ** readBinaryWatch(int num, int* returnSize){
    res = malloc(sizeof(char *) * 1024);
    memset(visited, 0, sizeof(visited));
     resSize = 0;
    backtrack(num, 0, 0, 0);
   
    *returnSize = resSize;
    return res;
}


// @lc code=end

