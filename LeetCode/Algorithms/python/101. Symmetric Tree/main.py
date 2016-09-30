# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        line, curLevel, ans = [], [], True
        line.append(root)
        curNum = 1
        nextNum = 0
        while line:
            head = line.pop(0)
            if head:
                curLevel.append(head.val)
            else:
                curLevel.append(None)
            curNum -= 1

            if head:
                line.append(head.left)
                line.append(head.right)
                nextNum += 2

            # Current level travel ends
            if not curNum:
                ans = self.checkSymmetric(curLevel)
                if not ans:
                    break
                curNum, nextNum = nextNum, 0
                curLevel = []
        return ans

    def checkSymmetric(self, level):
        length = len(level)
        for e in range(length // 2):
            if level[e] != level[length - 1 - e]:
                return False
        return True
