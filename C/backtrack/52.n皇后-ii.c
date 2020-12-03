/*
 * @lc app=leetcode.cn id=52 lang=c
 *
 * [52] N皇后 II
 */

// @lc code=start
int result;
void backtrack(int *columns, int *diagonals1, int *diagonals2, int n,  int row){
    if (row == n){
        ++result;
        return;
    }

    for (int i = 0; i < n; ++i){
        if (columns[i]) continue;
        int diagonal1 = row - i + n - 1;
        if (diagonals1[diagonal1]) continue;
        int diagonal2 = row + i;
        if (diagonals2[diagonal2]) continue;
        columns[i] = true;
        diagonals1[diagonal1] = true;
        diagonals2[diagonal2] = true;
        backtrack(columns, diagonals1, diagonals2, n, row + 1);
        columns[i] = false;
        diagonals1[diagonal1] = false;
        diagonals2[diagonal2] = false;
    
     }
}

int totalNQueens(int n){
    int columns[n];
    int diagonals1[n + n];
    int diagonals2[n + n];
   
    memset(columns, 0, sizeof(columns));
    memset(diagonals1, 0, sizeof(diagonals1));
    memset(diagonals2, 0, sizeof(diagonals2));

    result = 0;
    backtrack(columns, diagonals1, diagonals2, n, 0);

    return result;
}
// @lc code=end

