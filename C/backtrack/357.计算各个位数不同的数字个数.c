/*
 * @lc app=leetcode.cn id=357 lang=c
 *
 * [357] 计算各个位数不同的数字个数
 */

// @lc code=start


bool used[10];


int dfs(int n, int index){
    int count = 0;
    if (index != n){
        for (int i = 0; i < 10; ++i){
            if (i == 0 && n > 1 && index == 1){
                continue;
            }

            if (used[i]){
                continue;
            }

            used[i] = true;
            count += dfs(n, index + 1) + 1;
            used[i] = false;
        }
    }

    return count;
}

int countNumbersWithUniqueDigits(int n){
    if(n == 0) return 1;
    memset(used, 0, sizeof(used));
    return dfs(n, 0);
}
// @lc code=end

