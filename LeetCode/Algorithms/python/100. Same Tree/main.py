# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        return self.inorder(p, q)

    def inorder(self, p, q):
        if not p and not q:
            return True
        elif p and q:
            if p.val == q.val:
                return (self.inorder(p.left, q.left) and self.inorder(p.right, q.right))
            else:
                return False
        else:
            return False
