class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int Lsum =0, Rsum=0, sum=0;
        int n  = cardPoints.size();
        for(int i= 0; i<k; i++) {
            Lsum = Lsum + cardPoints[i];
        }
        sum = max(Lsum, sum);
        int rightIdx = n-1;
        for(int i=k-1; i>=0; i--) {
            Lsum = Lsum - cardPoints[i];
            Rsum += cardPoints[rightIdx];
            rightIdx--;
            sum = max(Lsum + Rsum, sum);
        }
        return sum;
    }
};