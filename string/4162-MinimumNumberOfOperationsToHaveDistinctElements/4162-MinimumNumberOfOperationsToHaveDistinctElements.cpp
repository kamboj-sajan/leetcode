// Last updated: 19/08/2026, 15:18:31
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0; i<nums.size(); ++i){
            mpp[nums[i]]++;
        }
        int b = 0;
        for(auto &a : mpp){
            if(a.second > 1){
            b++;
            }
        }
        if(b == 0)return 0;
        int cnt = 0;
        int i =0;
        int n = nums.size();
        while(i < n && b > 0){
            cnt++;
            for(int j=0; j<3 && i<n; j++,i++){
                int c = nums[i];
                mpp[c]--;
                if(mpp[c] == 1){
                    b--;
                }
            }
        }
        return cnt;
    }
};