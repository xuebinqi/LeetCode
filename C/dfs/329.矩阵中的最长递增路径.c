/*
 * @lc app=leetcode.cn id=329 lang=c
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start

int path;

int dfs(int **matrix, int x, int y, int row, int col, int **memo) {
    if (memo[x][y]) {
        return memo[x][y];
    }
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    ++memo[x][y];
    for (int i = 0; i < 4; ++i) {
        int a = x + dx[i];
        int b = y + dy[i];
        if (a >= 0 && a < row && b >= 0 && b < col && matrix[x][y] < matrix[a][b]) {
            memo[x][y] = fmax(memo[x][y], dfs(matrix, a, b, row, col, memo) + 1);
        }
    }

    return memo[x][y];
}


int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        return 0;
    }
    
    int row = matrixSize;
    int col = matrixColSize[0];
    int **memo = (int **) malloc(sizeof(int*) * row);
    for (int i = 0; i < row; ++i){
        memo[i] = malloc(sizeof(int) * col);
        memset(memo[i], 0, sizeof(int) * col);
    }

    int path = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            path = fmax(path, dfs(matrix, i, j, row, col, memo));
        }
    }
    for (int i = 0; i < row; ++i) {
        free(memo[i]);
    }

    free(memo);
    return path;
}


// @lc code=end

