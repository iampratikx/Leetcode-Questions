class Solution:
    def isPalindrome(self, x: int) -> bool:
        xx = x
        ans = 0
        while xx > 0:
            n = xx % 10
            xx = xx // 10
            ans = ans * 10 + n
        if ans == x:
            return True
        else:
            return False
