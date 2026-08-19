// Last updated: 19/08/2026, 15:32:30
// class Solution {
// public:
//     long long minimumRemoval(vector<int>& nums) {
//         using ll = long long;
//         int n = nums.size();
//         ll res = INT_MAX;
//         for(int i=0; i<n; ++i){
//             ll temp =0;
//             for(int j=0; j<n; ++j){
//                 if(nums[j] < nums[i]){
//                     temp += nums[j];
//                 }else{
//                     temp += (nums[j] - nums[i]);
//                 }
//             }
//             res = min(res,temp);
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     long long minimumRemoval(vector<int>& beans) {
//         using ll = long long;
//         int n = beans.size();
//         sort(beans.begin(),beans.end());
//         ll tot = 0;
//         for(int i : beans){
//             tot += i;
//         }
//         ll ans = LLONG_MAX;
//         for(int i=0; i<n; ++i){
//             ll keep = 1LL*beans[i]*(n-i);
//             ll remove = tot - keep;
//             ans = min(ans,remove);
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     long long minimumRemoval(vector<int>& beans) {
//         sort(beans.begin(), beans.end());
//         long long sum = accumulate(beans.begin(), beans.end(), 0LL);
//         long long ans = LLONG_MAX;
//         int n = beans.size();
//         for (int i = 0; i < n; i++) {
//             ans = min(ans, sum - 1LL * beans[i] * (n - i));
//         }
//         return ans;
//     }
// };

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(), beans.end());
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + beans[i];
        }
        long long ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            long long left = prefix[i];
            long long right = (prefix[n] - prefix[i]) 
                            - 1LL * beans[i] * (n - i);
            
            ans = min(ans, left + right);
        }
        return ans;
    }
};