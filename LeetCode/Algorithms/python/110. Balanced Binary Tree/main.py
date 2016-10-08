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
            leftDepth = self.isBalanced2(root.left)
            rightDepth = self.isBalanced2(root.right)
            diff = abs(leftDepth - rightDepth)
            ans = True if leftDepth >= 0 and rightDepth >= 0 and diff <= 1 else False
        return ans

    def isBalanced2(self, root):
        if not root:
            return 0
        else:
            leftDepth = self.isBalanced2(root.left)
            rightDepth = self.isBalanced2(root.right)
            diff = abs(leftDepth - rightDepth)
            if diff <= 1 and leftDepth >= 0 and rightDepth >= 0:
                return max(leftDepth, rightDepth) + 1
            else:
                return -1
