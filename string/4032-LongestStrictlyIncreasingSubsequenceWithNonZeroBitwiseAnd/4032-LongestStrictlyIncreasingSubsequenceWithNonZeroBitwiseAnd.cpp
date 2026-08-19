// Last updated: 19/08/2026, 15:21:11
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<31; ++i){
            vector<int> vec;
            for(int a : nums){
                if(a & (1 << i)){
                auto p = lower_bound(vec.begin(),vec.end(),a);
                if(p == vec.end()){
                    vec.push_back(a);
                }else{
                    *p = a;
                }
            }
        }
          ans = max(ans,(int)vec.size());  
        }
        return ans;
    }
};