class Matrix:
    def __init__(self, matr):
        self.matr = matr
        self.rows = len(matr)
        self.cols = len(matr[0])

    def __repr__(self):
        return '\n'.join(['\t'.join(map(str, row)) for row in self.matr])

    def __add__(self, other):
        # сложение матриц
        return Matrix([[self.matr[i][j] + other.matr[i][j] for j in range(self.cols)] for i in range(self.rows)])

    def __mul__(self, other):
        if isinstance(other, Matrix):
            # умножение матриц
            return Matrix([[sum(self.matr[i][k] * other.matr[k][j] for k in range(self.cols)) for j in range(other.cols)] for i in range(self.rows)])
        else:
            # умножение на число
            return Matrix([[x * other for x in row] for row in self.matr])

    __rmul__ = __mul__ 

    def __iter__(self):
        for row in self.matr:
            for x in row:
                yield x

    def det(self):
        # вычисление определителя (для квадратных матриц)
        if self.rows != self.cols:
            raise ValueError("Определитель находится только у квадратных матриц")
        return self._det(self.matr)

    def _det(self, matrix):
        n = len(matrix)
        if n == 1:
            return matrix[0][0]
        if n == 2:
            return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0]
        det = 0
        for c in range(n):
            minor = [row[:c] + row[c+1:] for row in matrix[1:]]
            det += ((-1) ** c) * matrix[0][c] * self._det(minor)
        return det

# пример    
A = Matrix([[1, 2], [3, 4]])
B = Matrix([[5, 6], [7, 8]])

print(A + B, '\n')

print(A * B, '\n')

print(A * 3)

print("Определитель A =", A.det())

print("Итерация по элементам A:")
for x in A:
    print(x)
