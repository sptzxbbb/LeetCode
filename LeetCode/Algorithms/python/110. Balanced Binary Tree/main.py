# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        ans = None
        if not root:
            ans = True
        else:
            leftBalanced, leftDepth = self.isBalanced2(root.left)
            rightBalanced, rightDepth = self.isBalanced2(root.right)
            diff = abs(leftDepth - rightDepth)
            ans = True if leftBalanced and rightBalanced and diff <= 1 else False
        return ans

    def isBalanced2(self, root):
        if not root:
            return (True, 0)
        else:
            leftBalanced, leftDepth = self.isBalanced2(root.left)
            rightBalanced, rightDepth = self.isBalanced2(root.right)
            diff = abs(leftDepth - rightDepth)
            balanced = None
            height = max(leftDepth, rightDepth) + 1
            balanced = True if leftBalanced and rightBalanced and diff <= 1 else False
            return (balanced, height)
