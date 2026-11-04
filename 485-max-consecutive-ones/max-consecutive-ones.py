class Solution:
    def findMaxConsecutiveOnes(self, nums):
        n=len(nums)
        count=0
        max_count=0
        for i in range(0,n):
            if nums[i]==1:
                count+=1
            else:
                max_count=max(max_count,count)
                count=0
        max_count=max(max_count,count)
        return max_count