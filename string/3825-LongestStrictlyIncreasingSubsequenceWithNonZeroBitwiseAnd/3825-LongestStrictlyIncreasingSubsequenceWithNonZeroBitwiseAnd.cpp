// Last updated: 25/09/2026, 00:54:54
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