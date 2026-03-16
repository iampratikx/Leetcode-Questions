class Solution:
    def repeatedCharacter(self, s: str) -> str:
        mpp = {}
        for i in s:
            if i in mpp:
                return i
            else:
                mpp[i] = 1
        return -1