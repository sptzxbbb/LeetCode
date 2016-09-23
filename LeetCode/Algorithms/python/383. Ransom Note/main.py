import collections

class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        d = {}
        for c in magazine:
            if c not in d:
                d[c] = 1
            else:
                d[c] += 1
        for c in ransomNote:
            if c not in d:
                return False
            else:
                d[c] -= 1
                if d[c] < 0:
                    return False
        return True


class Solution1(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        cnt = collections.Counter(magazine)
        for letter in ransomNote:
            cnt[letter] -= 1
            if cnt[letter] < 0:
                return False
        return True


class Solution2(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        ransomCnt = collections.Counter(ransomNote)
        magazineCnt = collections.Counter(magazine)
        return not ransomCnt - magazineCnt
