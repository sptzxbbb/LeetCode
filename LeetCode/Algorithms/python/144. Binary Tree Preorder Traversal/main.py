# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        return self.preorderIterative(root)

    def preorderRecursive(self, node, ans):
        if not node:
            return
        ans.append(node.val)
        self.preorderRecursive(node.left, ans)
        self.preorderRecursive(node.right, ans)

    def preorderIterative(self, root):
        stack = []
        ans = []
        if root:
            stack.append(root)
        while len(stack):
            node = stack.pop()
            ans.append(node.val)
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)
        return ans
