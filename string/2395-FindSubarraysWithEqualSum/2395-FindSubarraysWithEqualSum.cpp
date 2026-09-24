// Last updated: 25/09/2026, 01:05:04
// class Solution {
// public:
//     bool findSubarrays(vector<int>& nums) {
//         unordered_map<int,int> mpp;
//         if(nums.size() <= 2)return false;
//         for(int i=0; i<nums.size()-1; i++){
//             long long sum = 0;
//             for(int j=i; j<i+2; j++){
//                 sum += nums[j];
//             }
//             mpp[sum]++;
//             if(mpp[sum] == 2)return true;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        for(int i=0;i<n-1;i++){
            int l=nums[i];
            int r=nums[i+1];
            int sum=l+r;
            if(st.find(sum) != st.end()){
                return true;
            }
           st.insert(sum);
        }
        return false;
    }
};