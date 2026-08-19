// Last updated: 19/08/2026, 16:03:57
// class Solution {
// void f(vector<int> &nums,vector<int> &ans,int ind,int k){
//     if(ind+k > nums.size())return;
//     long maxa = INT_MIN;
//     for(long i=ind; i<ind+k; i++){
//         maxa = max(maxa,(long)nums[i]);
//     }
//     ans.push_back((int)maxa);
//     f(nums,ans,ind+1,k);
// }
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> ans;
//         f(nums,ans,0,k);
//         return ans;
//     }
// }; tle 40/54

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> ans;
//         int ind = 0;
//         while(ind + k <= nums.size()){
//             int maxa = INT_MIN;
//             for(int i=ind; i<ind+k; i++){
//                 maxa = max(nums[i],maxa);
//             }
//             ans.push_back(maxa);
//             ind++;
//         }
//         return ans;
//     }
// }; tle after 39

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> ans;
      deque<int> dq;
      for(int i=0; i<n; i++){
        if(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()] <= nums[i])dq.pop_back();
        dq.push_back(i);
        if(i>=k-1)ans.push_back(nums[dq.front()]);
      }
      return ans;
    }
};