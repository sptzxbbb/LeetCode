class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        res = []
        for i in range(numRows):
            curRow = []
            for j in range(i + 1):
                if j == 0:
                    curRow = [1]
                else:
                    if j != 0 and j != i:
                        curRow.append(res[i - 1][j - 1] + res[i - 1][j])
                    elif j == 0 or j == i:
                        curRow.append(1)
            res.append(curRow)
        return res
