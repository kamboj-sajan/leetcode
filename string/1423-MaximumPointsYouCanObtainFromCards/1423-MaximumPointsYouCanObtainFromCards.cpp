// Last updated: 25/09/2026, 01:13:02
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        long lsum = 0 , rsum = 0;
        int n = cardPoints.size();
        long maxsum = 0;
        for(int i = 0; i<k; i++)lsum += cardPoints[i];
        maxsum = lsum;
        int rindex = n - 1;
        for(int i = k-1; i >= 0; i--){
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[rindex];
            rindex = rindex - 1;
            maxsum = max(maxsum ,(lsum + rsum));
        }
        return maxsum;
    }
};