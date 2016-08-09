class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        row = []
        for i in range(rowIndex + 1):
            for j in range(i, -1, -1):
                if j == i:
                    row.append(1)
                elif j > 0:
                    row[j] = row[j - 1] + row[j]
        return row
