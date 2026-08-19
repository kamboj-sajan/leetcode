// Last updated: 19/08/2026, 15:15:24
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int mod = 1e9 + 7;
        vector<int> vec(3,0);
        long long ans =0;
        for(auto it :  nums){
            int el;
            if(it < a)el = 0;
            else if(it <= b) el= 1;
            else el=2;
            if(el == 0){
                ans += vec[1] + vec[2];
            }else if(el == 1){
                ans += vec[2];
            }
            vec[el]++;
        }
        return ans%mod;
    }
};