class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
          int len= piles.size();

        int left = 1;

        auto it = max_element(piles.begin(),piles.end());
        int right = *it;
       
        int result = right;      

        while(left <= right)
        {
            int k = left + (right-left)/2;
            long hours = 0;
            for(int i = 0; i < len; i++)
            {
                hours += ceil(((double)piles[i])/k);                                                           
            }

            if(hours <= h) // valid k, check for k less than this
            {
                result = k;
                right = k-1;
            }
            else
            {
                left = k+1;
            }
        }

        return result;
    }
};