# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        return self.postorderIterative(root)

    def postorderRecurisve(self, node, ans):
        if node:
            self.postorderRecurisve(node.left, ans)
            self.postorderRecurisve(node.right, ans)
            ans.append(node.val)

    def postorderIterative(self, root):
        ans = []
        stack = []
        if root:
            stack.append(root)
        while len(stack):
            node = stack.pop()
            ans.append(node.val)
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        ans = ans[::-1]
        return ans
