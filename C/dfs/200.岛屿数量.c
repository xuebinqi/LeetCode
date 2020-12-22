/*
 * @lc app=leetcode.cn id=200 lang=c
 *
 * [200] 岛屿数量
 */

// @lc code=start

int m;
int n;
void dfs(char **grid, int row, int col){
    grid[row][col] = '0';
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; ++i){
        int x = row + dx[i];
        int y = col + dy[i];
        if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == '1'){
            dfs(grid, x, y);
        }
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if (!grid) return 0;
    if (gridSize == 0) return 0;

    int res = 0;
    m = gridSize;
    n = *gridColSize;
    for (int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j) {
            if (grid[i][j] == '1'){
                ++res;
                dfs(grid, i, j);
            }
        }
    }
    
    return res;
}
// @lc code=end

