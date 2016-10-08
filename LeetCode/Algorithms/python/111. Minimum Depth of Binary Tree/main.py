# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        else:
            line = [root]
            curNum, nextNum = 1, 0
            depth = 0
            stop = False
            while not stop:
                head = line.pop(0)
                curNum -= 1
                if not head.left and not head.right:
                    stop = True
                    depth += 1
                    continue

                if head.left:
                    line.append(head.left)
                    nextNum += 1
                if head.right:
                    line.append(head.right)
                    nextNum += 1

                if not curNum:
                    curNum, nextNum = nextNum, 0
                    depth += 1
        return depth
