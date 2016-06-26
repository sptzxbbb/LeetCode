class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ans = []
        for i in range(1, n + 1):
            e = ""
            if i % 3 == 0:
                e += "Fizz"
            if i % 5 == 0:
                e += "Buzz"
            if not e:
                e = str(i)
            ans.append(e)
        return ans
