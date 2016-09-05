# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        s = [0]
        self.travel(root, "right", s)
        return s[0]

    def travel(self, node, _type, s):
        if not node:
            return
        else:
            if not node.left and not node.right:
                if _type == "left":
                    s[0] += node.val
                else:
                    pass
            else:
                self.travel(node.left, "left", s)
                self.travel(node.right, "right", s)
