// Last updated: 28/09/2026, 09:54:01
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        map<int,int> mpp;
        for(int i : nums){
            mpp[i]++;
        }
        while(!mpp.empty()){
            vector<int> temp;
            for(auto &p : mpp){
                ans.push_back(p.first);
                p.second--;
                if(p.second == 0){
                    temp.push_back(p.first);
                }
            }
            for(int i : temp)mpp.erase(i);
        }
        return ans;
    }
};