// Last updated: 19/08/2026, 15:18:37
using ll = long long;
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec[3];
        for(int p : nums){
            vec[p%3].push_back(p);
        }
        for(int i=0; i<3; ++i){
            sort(vec[i].rbegin(),vec[i].rend());
        }
        ll ans = 0;
        if(vec[0].size() >= 3){
            ans = max(ans,(ll)vec[0][0]+vec[0][1]+vec[0][2]);
        }
        if(vec[1].size()>=3){
            ans = max(ans,(ll)vec[1][0]+vec[1][1]+vec[1][2]);
        }
        if(vec[2].size() >= 3){
            ans = max(ans,(ll)vec[2][0]+vec[2][1]+vec[2][2]);
        }
        if(!vec[0].empty() && !vec[1].empty() && !vec[2].empty()){
            ans = max(ans,(ll)vec[0][0]+vec[1][0]+vec[2][0]);
        }
        return (int)ans;
    }
};