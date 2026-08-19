// Last updated: 19/08/2026, 15:30:36
// class Solution {
// public:
//     vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
//         int n = nums.size();
//         int m = queries.size();
//         using ll = long long;
//         vector<ll> ans;
//         for(int i=0; i<m; ++i){
//             ll temp = 0;
//             for(int j=0; j<n; ++j){
//                 temp += abs(nums[j]-queries[i]);
//             }
//             ans.push_back(temp);
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
//         using ll = long long;
//         int n = nums.size();
//         int m = queries.size();
//         vector<pair<int,int>> vec;
//         // mark nums as type 0
//         for (int num : nums) {
//             vec.push_back({num, 0});
//         }
//         // mark queries as type 1
//         for (int i = 0; i < m; i++) {
//             vec.push_back({queries[i], 1});
//         }
//         sort(vec.begin(), vec.end());  // 🔥 MUST
//         ll sum = 0;
//         ll total = 0;
//         for (int num : nums) total += num;
//         int count = 0;
//         unordered_map<int, ll> mp;
//         for (auto &p : vec) {
//             int val = p.first;
//             int type = p.second;
//             if (type == 0) {
//                 // it's a number
//                 sum += val;
//                 count++;
//             } else {
//                 // it's a query
//                 ll left = 1LL * val * count - sum;
//                 ll right = (total - sum) - 1LL * val * (n - count);
//                 mp[val] = left + right;
//             }
//         }
//         vector<ll> ans;
//         for (int q : queries) {
//             ans.push_back(mp[q]);
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
//         using ll = long long;
//         int n = nums.size();
//         sort(nums.begin(),nums.end());
//         vector<ll> pre(n+1,0);
//         for(int i=0; i<n; ++i){
//             pre[i+1] = pre[i] + nums[i];
//         }
//         vector<ll> ans;
//         for(int q : queries){
//             int ind = upper_bound(nums.begin(),nums.end(),q) - nums.begin();//first ind having nums[ind] > q
//             ll l = 1LL*q*ind - pre[ind];
//             ll r = (pre[n] - pre[ind]) - 1LL*q*(n-ind);
//             ans.push_back(l+r);
//         }
//         return ans;
//     }
// };

class Solution {
public:
  int findidx(vector<int>&nums,int q){
        long long int idx=nums.size(),start=0,end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(q<nums[mid]){
              idx=mid;
              end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return idx;
       }  
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {   
       
       int n=nums.size();
       int m=queries.size();
       vector<long long>ans;
       vector<long long>prefix(n+1,0);
       sort(nums.begin(),nums.end());
       //find the prefix sum array
       for(int i=0;i<n;i++){
        prefix[i+1]=prefix[i]+nums[i];
       }
       long long int left_sum=0,right_sum=0,total_sum,idx;
       for(int j=0;j<m;j++){
        idx=findidx(nums,queries[j]);
        left_sum=(queries[j]*idx)-prefix[idx];
        right_sum=(prefix[n]-prefix[idx])-(queries[j]*(n-idx));
        total_sum=left_sum+right_sum;
        ans.push_back(total_sum);
       }
       return ans;
       
    }
   
};