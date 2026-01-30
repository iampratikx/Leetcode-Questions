class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 =0,cnt2 =0;
        vector<int> ans;
        int len = nums.size();
        int ele1 =INT_MIN, ele2 =INT_MIN;
        for(int i=0;i<len; i++){
            if(cnt1==0 && ele2 != nums[i]){
                ele1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2==0 && ele1 != nums[i]){
                ele2 =nums[i];
                cnt2 = 1;
            }
            else if(ele1==nums[i]) cnt1++;
            else if(ele2==nums[i]) cnt2++;
            else cnt1--,cnt2--;
        }
        int elecnt1=0, elecnt2=0;
        for(int i=0;i<len; i++){
            if(ele1==nums[i]) elecnt1++;
            else if(ele2 == nums[i]) elecnt2++;
        }
        if(elecnt1>len/3) ans.push_back(ele1);
        if(elecnt2>len/3) ans.push_back(ele2);
        return ans;
    }
};