class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        size = 9
        for i in range(size):
            row = board[i]
            if not self.isValid(row):
                return False

            col = [board[j][i] for j in range(size)]
            if not self.isValid(col):
                return False

            block = [board[i // 3 * 3+ j // 3][i % 3 * 3 + j % 3] for j in range(size)]
            if not self.isValid(block):
                return False
        return True

    def isValid(self, l):
        d = set([])
        for e in l:
            if e == ".":
                continue
            if e in d:
                return False
            if e not in d:
                d.add(e)
        return True
