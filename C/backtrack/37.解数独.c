/*
 * @lc app=leetcode.cn id=37 lang=c
 *
 * [37] 解数独
 */

// @lc code=start

bool line[9][9];
bool column[9][9];
bool block[3][3][9];

bool valid;
int *space[81];
int spaceSize;

void backtrack(char**board, int pos){
    if (pos == spaceSize){
        valid = true;
        return ;
    }

    int i = space[pos][0], j = space[pos][1];
    for (int digit = 0; digit < 9 && !valid; ++digit){
        if (!line[i][digit] && !column[j][digit] && !block[i / 3][j / 3][digit]){
            line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
            board[i][j] = digit + '0' + 1;
            backtrack(board, pos + 1);
            line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = false;
        }
    }
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
    memset(line, false, sizeof(line));
    memset(column, false, sizeof(column));
    memset(block, false, sizeof(block));
    valid = false;
    spaceSize = 0;

    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            if (board[i][j] == '.'){
                space[spaceSize] = malloc(sizeof(int) * 2);
                space[spaceSize][0] = i;
                space[spaceSize++][1] = j;
            } else{
                int digit = board[i][j] - '0' - 1;
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
            }
        }
    }

    backtrack(board, 0);
}
// @lc code=end

