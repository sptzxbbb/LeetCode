# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def hasPathSum(self, root, target):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if not root:
            return False
        res = [False]
        start = 0
        self.dfs(root, start, target, res)
        return res[0]

    def dfs(self, root, s, target, res):
        if res[0]:
            return

        s += root.val
        if s == target and not root.left and not root.right:
            res[0] = True
            return

        if root.left:
            self.dfs(root.left, s, target, res)
        if root.right:
            self.dfs(root.right, s, target ,res)

        s -= root.val
