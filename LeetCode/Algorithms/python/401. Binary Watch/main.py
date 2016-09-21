from itertools import combinations

class Solution(object):
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        ans = []
        for i in range(0, min(num, 4) + 1):
            hour = self.get_hour(i)
            j = num - i
            minute = self.get_minute(j)
            time = self.get_time(hour, minute)
            ans += time
        return ans

    def get_hour(self, i):
        hour_weight = [8, 4, 2, 1]
        ans = []
        for h in combinations(hour_weight, i):
            s = sum(h)
            if s < 12 and s >= 0:
                ans.append(s)
        return ans

    def get_minute(self, i):
        if i >= 6:
            return []
        minute_weight = [32, 16, 8, 4, 2, 1]
        ans = []
        for m in combinations(minute_weight, i):
            s = sum(m)
            if s < 60 and s >= 0:
                ans.append(s)
        return ans

    def get_time(self, hour, minute):
        hour = map(lambda x: str(x), hour)
        minute = map(lambda x: str(x) if x >= 10 else ("0" + str(x)), minute)
        res = []
        for h in hour:
            for m in minute:
                res.append(h + ":" + m)
        return res
