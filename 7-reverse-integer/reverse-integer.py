class Solution:
    def reverse(self, x: int) -> int:
        ans = 0
        signpositive = True
        if x < 0:
            signpositive = False
            x = x * -1
        while(x > 0):
            n = x%10
            x = x // 10
            ans = ans*10 + n
        if signpositive == False:
            ans = -1 * ans
        if ans < -(2**31) or ans > (2**31 -1):
            return 0
        return ans
        