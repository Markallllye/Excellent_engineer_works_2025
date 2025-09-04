def is_valid(board, row, col, num, size):
    # 检查行
    for x in range(size):
        if board[row][x] == num:
            return False
    # 检查列
    for x in range(size):
        if board[x][col] == num:
            return False
    # 检查宫
    start_row, start_col = row - row % (size // (2 if size == 4 else 3)), col - col % (size // (2 if size == 4 else 3))
    for i in range(start_row, start_row + (size // (2 if size == 4 else 3))):
        for j in range(start_col, start_col + (size // (2 if size == 4 else 3))):
            if board[i][j] == num:
                return False
    return True

def solve_sudoku(board, size):
    for row in range(size):
        for col in range(size):
            if board[row][col] == 0:
                for num in range(1, size + 1):
                    if is_valid(board, row, col, num, size):
                        board[row][col] = num
                        if solve_sudoku(board, size):
                            return True
                        board[row][col] = 0
                return False
    return True

# 输入解题类型
print("请输入解题类型：")
print("请输入4或者9行数字：")
size = int(input())
board = []
# 输入数独题目
for _ in range(size):
    row = list(map(int, input().split()))
    board.append(row)

solve_sudoku(board, size)
# 输出数独题解
for row in board:
    print(" ".join(map(str, row)))