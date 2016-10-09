class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    # @param {TreeNode} root
    # @return {string[]}
    def binaryTreePaths(self, root):
        path, ans = [], []
        self.dfs(root, path, ans)
        for idx, _ in enumerate(ans):
            ans[idx] = '->'.join(ans[idx])
        return ans

    def dfs(self, node, path, ans):
        if node:
            path.append(str(node.val))
            if node.left:
                self.dfs(node.left, path, ans)
            if node.right:
                self.dfs(node.right, path, ans)
            if (not node.left) and (not node.right):
                ans.append(path[:])
            path.pop()


def main():
    l = [TreeNode(1), TreeNode(2), TreeNode(3), TreeNode(5)]
    l[0].left = l[1]
    l[0].right = l[2]
    l[1].right = l[3]
    s = Solution()
    ans = s.binaryTreePaths(l[0])
    print(ans)


if __name__ == '__main__':
    for x in range(10):
        pass

    print(x)
