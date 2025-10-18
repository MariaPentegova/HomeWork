#перебор
def is_valid(row, col, board): 
    # проверка, бьются ли ферзи в той же строке или диагоналях 
    for i in range(row): 
        if board[i] == col or board[i] - i == col - row or board[i] + i == col + row: 
            return False 
    return True 
def solve(size, row, board, results): 
    # если все столбцы заполнены, добавляем расстановку ферзей в результаты 
    if row == size: 
        results.append(board[:]) 
        return 
    # пытаемся поставить ферзя в каждую строку текущего столбца 
    for col in range(size): 
        if is_valid(row, col, board): 
            board[row] = col 
            solve(size, row+1, board, results) 
            board[row] = -1 
def find_all_solutions(size): 
    results = [] 
    board = [-1] * size 
    solve(size, 0, board, results) 
    return results
 
n = int(input())
all_solutions = find_all_solutions(n) # найдем все расстановки ферзей на доске 
c = 0
if n>=4:
    for solution in all_solutions: 
        c+=1
    print(c) 
elif n==1:
    print(1)
else:
    print(0)
#рекурсия
def solve(n):
    def is_safe(board, row, col):
        for prev_col in range(col):
            prev_row = board[prev_col]
            if prev_row == row:
                return False
            if abs(prev_row - row) == abs(prev_col - col):
                return False
        return True
    def set_quin(col, current_board, solutions):
        if col == n:
            solutions.append(current_board)
            return
        for row in range(n):
            if is_safe(current_board, row, col):
                current_board.append(row)
                set_quin(col + 1, current_board, solutions)
                current_board.pop()
    solutions = []
    set_quin(0, [], solutions)
    return solutions 

N = int(input())
print(len(solve(N)))


