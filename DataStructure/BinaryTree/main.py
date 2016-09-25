#! /usr/bin/env python3
# -*- coding: utf-8 -*-

class Node():
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        return self.inorderIterative(root)

    def inorderRecursive(self, node, ans):
        if not node:
            return
        self.inorderRecursive(node.left, ans)
        ans.append(node.val)
        self.inorderRecursive(node.right, ans)
        return

    def inorderIterative(self, root):
        stack = []
        ans = []
        node = root
        while (len(stack) or node):
            if (node):
                stack.append(node)
                node = node.left
            else:
                node = stack.pop()
                ans.append(node.val)
                node = node.right
        return ans
