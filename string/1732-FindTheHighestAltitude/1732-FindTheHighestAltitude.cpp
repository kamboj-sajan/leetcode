// Last updated: 25/09/2026, 01:10:17
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int cnt =0;
        int maxi = 0;
        for(int i=0; i<n; ++i){
            cnt += gain[i];
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};