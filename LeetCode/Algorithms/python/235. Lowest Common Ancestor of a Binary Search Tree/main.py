# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if not root or not p or not q:
            return None

        path1 = self.getPath(root, p)
        path2 = self.getPath(root, q)
        while path1[-1] != path2[-1]:
            if len(path1) > len(path2):
                path1.pop()
            else:
                path2.pop()
        return path1[-1]

    def getPath(self, root, node):
        val = node.val
        cur = root
        path = []
        while True:
            path.append(cur.val)
            if val == cur.val:
                break
            elif val > cur.val:
                cur = cur.right
            else:
                cur = cur.left
        return path
