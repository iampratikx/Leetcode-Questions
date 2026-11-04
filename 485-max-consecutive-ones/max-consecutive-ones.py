class Solution:
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        ans = 0
        cnt = 0
        for i in range(len(nums)):
            if nums[i] != 1:
                cnt = 0
            if nums[i] == 1:
                cnt +=1
            if cnt > ans:
                ans = cnt

        return ans

