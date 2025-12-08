class FrozenMatrix:
    def __init__(self, matr):
        # Преобразуем входные данные во вложенные кортежи для неизменяемости
        self._matr = tuple(tuple(row) for row in matr)
        self._rows = len(self._matr)
        self._cols = len(self._matr[0]) if self._rows > 0 else 0

        # Вычисляем хеш один раз для оптимизации
        self._hash = None

    @property
    def matr(self):
        return self._matr

    def __repr__(self):
        return '\n'.join(['\t'.join(map(str, row)) for row in self._matr])

    def __eq__(self, other):
        if not isinstance(other, FrozenMatrix):
            return NotImplemented
        return self._matr == other._matr

    def __hash__(self):
        if self._hash is None:
            self._hash = hash(self._matr)
        return self._hash

    @property
    def shape(self):
        return (self._rows, self._cols)  
