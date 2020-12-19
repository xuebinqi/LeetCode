/*
 * @lc app=leetcode.cn id=130 lang=c
 *
 * [130] 被围绕的区域
 */

// @lc code=start

int m, n;

void dfs(char **board, int x, int y){
    if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O'){
        return ;
    }
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    board[x][y] = '#';
    for (int i = 0; i < 4; ++i){
        int a = x + dx[i];
        int b = y + dy[i];
        if (a >= 0 && a < m && b >= 0 && b < n){
            dfs(board, a, b);
        }
    }
}

void solve(char** board, int boardSize, int* boardColSize){
    if (boardSize == 0) return;
    m = boardSize;
    n = *boardColSize;
    
    if (boardSize == 0 || (*boardColSize) == 0) return ;
    for (int i = 0; i < m; ++i){
        dfs(board, i, 0);
        dfs(board, i, n - 1);
    }

    for (int i = 1; i < n - 1; ++i){
        dfs(board, 0, i);
        dfs(board, m - 1, i);
    }

    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            if (board[i][j] == '#'){
                board[i][j] = 'O';
            } else if (board[i][j] == 'O'){
                board[i][j] = 'X';
            }
        }
    }
}
// @lc code=end

