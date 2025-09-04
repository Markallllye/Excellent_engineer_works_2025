#include <stdio.h>

int is_valid(int board[9][9], int row, int col, int num, int size) {
    // 检查行
    for (int x = 0; x < size; x++) {
        if (board[row][x] == num) {
            return 0;
        }
    }
    // 检查列
    for (int x = 0; x < size; x++) {
        if (board[x][col] == num) {
            return 0;
        }
    }
    // 检查宫
    int start_row = row - row % (size / (size == 4 ? 2 : 3));
    int start_col = col - col % (size / (size == 4 ? 2 : 3));
    for (int i = start_row; i < start_row + (size / (size == 4 ? 2 : 3)); i++) {
        for (int j = start_col; j < start_col + (size / (size == 4 ? 2 : 3)); j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve_sudoku(int board[9][9], int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= size; num++) {
                    if (is_valid(board, row, col, num, size)) {
                        board[row][col] = num;
                        if (solve_sudoku(board, size)) {
                            return 1;
                        }
                        board[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    printf("请输入解题类型：");
    printf("请输入4或者9行数字：");
    int size;
    // 输入解题类型
    scanf("%d", &size);
    int board[9][9];
    // 输入数独题目
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    solve_sudoku(board, size);
    // 输出数独题解
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}