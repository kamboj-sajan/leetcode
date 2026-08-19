// Last updated: 19/08/2026, 15:37:25
// class Solution {
// public:
//     int maximumUniqueSubarray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> pre(n);
//         unordered_set<int> st;
//         int i = 0;
//         int j = 0;
//         int ans = 0;
//         int maxi = INT_MIN;
//         while(j < n){
//             while(st.count(nums[j])){
//                 st.erase(nums[i]);
//                 ans -= nums[i];
//                 i++;
//             }
//             st.insert(nums[j]);
//             ans += nums[j];
//             maxi = max(ans,maxi);
//             j++;
//         }
//         return maxi;
//     }
// };

// class Solution {
// public:
//     static int maximumUniqueSubarray(vector<int>& nums) {
//         const int n=nums.size();
//         bitset<10001> hasX=0;
//         int ans=0, wsum=0;
//         for (int l=0, r=0; r<n; r++) {
//             const int x=nums[r];
//             while (hasX[x]) {
//                 hasX[nums[l]]=0;
//                 wsum-=nums[l];
//                 l++;
//             }
//             hasX[x]=1;
//             wsum+=x;
//             ans=max(ans, wsum);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> freq(10001, 0);
        int l = 0;
        long long sum = 0, ans = 0;
        for (int r = 0; r < nums.size(); r++) {
            freq[nums[r]]++;
            sum += nums[r];

            while (freq[nums[r]] > 1) {
                freq[nums[l]]--;
                sum -= nums[l];
                l++;
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};
