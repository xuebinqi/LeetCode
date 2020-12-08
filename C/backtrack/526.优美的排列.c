/*
 * @lc app=leetcode.cn id=526 lang=c
 *
 * [526] 优美的排列
 */

// @lc code=start

int count;
int *visited;

void backtrack(int n, int pos){
    if (pos > n) {
        ++count;
    }

    for (int i = 1; i <= n; ++i){
        if (!visited[i] && (pos % i == 0 || i % pos == 0)){
            visited[i] = 1;
            backtrack(n, pos + 1);
            visited[i] = 0;
        }
    }
}


int countArrangement(int N){
    visited = malloc(sizeof(int) * (N + 1));
    memset(visited, 0, sizeof(int) * (N + 1));
    count = 0;
    backtrack(N, 1);
   
    return count;
}


// @lc code=end

