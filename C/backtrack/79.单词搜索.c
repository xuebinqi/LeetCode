/*
 * @lc app=leetcode.cn id=79 lang=c
 *
 * [79] 单词搜索
 */

// @lc code=start


int rows;
int columns;

bool backtrack(char **board, char *word, int x, int y, int index){
    if (board[x][y] != word[index]) return false;
    if (strlen(word) - 1 == index) return true;
    char tmp = board[x][y];
    board[x][y] = 0;
    ++index;
    if (x > 0 && backtrack(board, word, x - 1, y, index) ||
        x < rows - 1 && backtrack(board, word, x + 1, y, index) ||
        y > 0 && backtrack(board, word, x, y - 1, index) ||  
        y < columns - 1 && backtrack(board, word, x, y + 1, index)
    ) {
        return true;
    }
    board[x][y] = tmp;

    return false;
}

bool exist(char **board, int boardSize, int *boardColSize, char *word){
    rows = boardSize;
    columns = *boardColSize;
    for (int i = 0; i < boardSize; ++i){
        for (int j = 0; j < (*boardColSize); ++j){
            if (backtrack(board, word, i, j, 0)){
                return true;
            }
        }
    }

    return false;
}
// @lc code=end

