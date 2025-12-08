class Matrix:
    def __init__(self, matr):
        self.matr = matr
        self.rows = len(matr)
        self.cols = len(matr[0]) if matr else 0

    def __repr__(self):
        #получение матрицы в читаемом виде
        return '\n'.join(['\t'.join(map(str, row)) for row in self.matr])

    def to_mtx(self):
        """
        Сериализация матрицы
        """
        lines = []
        lines.append("%%MatrixMarket matrix coordinate real general")
        # Подсчет ненулевых элементов
        nnz = sum(1 for row in self.matr for val in row if val != 0)
        lines.append(f"{self.rows} {self.cols} {nnz}")
        for i in range(self.rows):
            for j in range(self.cols):
                val = self.matr[i][j]
                if val != 0:
                    lines.append(f"{i+1} {j+1} {val}")
        return '\n'.join(lines)

    @staticmethod #так как далее вспомогательные
    def from_mtx(mtx_str):
        """
        Десериализация
        """
        lines = mtx_str.strip().splitlines()
        # пропускаем комментарии
        matr_lines = [line for line in lines if not line.startswith('%') and line.strip() != '']

        header = matr_lines[0].split()
        rows, cols, nnz = map(int, header)
        matr_lines = matr_lines[1:]

        # создаем матрицу нулей
        matr = [[0.0 for _ in range(cols)] for _ in range(rows)]
        for line in matr_lines:
            i_str, j_str, val_str = line.split()
            i, j = int(i_str), int(j_str)
            val = float(val_str)
            matr[i - 1][j - 1] = val
        return Matrix(matr)
    
#пример
A = Matrix([[1, 0, 2], [8, 3, 0], [4, 1, 5]])

# Сериализация в MTX
mtx_str = A.to_mtx()
print(mtx_str, "\n")

# Десериализация из MTX
A_2 = Matrix.from_mtx(mtx_str)
print(A_2)
