# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        line, curLevel, ans = [], [], []
        line.append(root)
        curNum = 1
        nextNum = 0
        while line:
            head = line.pop(0)
            curLevel.append(head.val)
            curNum -= 1
            if head.left:
                line.append(head.left)
                nextNum += 1
            if head.right:
                line.append(head.right)
                nextNum += 1
            # Current level travel ends
            if not curNum:
                curNum, nextNum = nextNum, 0
                ans.append(curLevel)
                curLevel = []
        return ans
