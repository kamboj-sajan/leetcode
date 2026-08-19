// Last updated: 19/08/2026, 15:22:33
class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0)return false;
        if(k <= 0)return false;
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        int g = n/k;
        for(auto &a : mpp){
            if(a.second > g)return false;
        }
        if(n%k == 0)return true;
        else return false;
    }
};