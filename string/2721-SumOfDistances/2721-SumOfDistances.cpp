// Last updated: 19/08/2026, 15:30:32
// class Solution {
// public:
//     vector<long long> distance(vector<int>& nums) {
//         int n = nums.size();
//         using ll = long long;
//         vector<ll> res;
//         for(int i=0; i<n; ++i){
//             ll temp = 0;
//             for(int j = 0; j<n; ++j){
//                 if(i ==j)continue;
//                 if(nums[i] == nums[j]){
//                     temp += abs(i-j);
//                 }
//             }
//             res.push_back(temp);
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<long long> distance(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,vector<int>> mpp;
//         for(int i=0; i<n; ++i){
//             mpp[nums[i]].push_back(i);
//         }
//         using ll = long long;
//         vector<ll> ans(n,0);
//         for(auto &it : mpp){
//             vector<int> &ind = it.second;
//             int k = ind.size();
//             vector<ll> pre(k+1,0);
//             for(int i=0; i<k; ++i){
//                 pre[i+1] = pre[i] + ind[i];
//             }
//             for(int i=0; i<k; ++i){
//                 ll left = (ll)i*ind[i] - pre[i];
//                 ll right = (pre[k] - pre[i+1]) - (ll)(k-i-1)*ind[i];
//                 ans[ind[i]] = left + right;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int, array<long long,4>> map;
        map.reserve(n * 2);
        for (int i = 0; i < n; ++i) {
            auto &a = map[nums[i]];
            a[0] += i;
            ++a[1];
        }
        vector<long long> res(n);
        for (int i = 0; i < n; ++i) {
            auto &a = map[nums[i]];
            long long sumR = a[0], cntR = a[1], sumS = a[2], cntS = a[3];
            res[i] = sumR - cntR * i + cntS * i - sumS;
            a[0] -= i; --a[1];
            a[2] += i; ++a[3];
        }
        return res;
    }
};