// Last updated: 19/08/2026, 15:32:47
// class Solution {
// public:
//     vector<int> findLonely(vector<int>& nums) {
//        int n =  nums.size();
//        if(n == 1)return {nums[0]};
//        sort(nums.begin(),nums.end());
//        vector<int> ans;
//        if(nums[0]+1 != nums[1] && nums[0] != nums[1])ans.push_back(nums[0]);
//        for(int i=1; i<n-1; ++i){
//         if(nums[i]+1 != nums[i+1] && nums[i]-1 != nums[i-1] && nums[i] != nums[i+1] && nums[i] != nums[i-1]){
//             ans.push_back(nums[i]);
//         }
//        }
//        if(nums[n-1]-1 != nums[n-2] && nums[n-1] != nums[n-2])ans.push_back(nums[n-1]);
//        return ans;
//     }
// };

// vector<int>a(1000005);
// class Solution {
// public:
//     vector<int> findLonely(vector<int>& n) {
//         vector<int>b;
//         for(int i:n)a[i+1]++;
//         for(int i:n){
//             if(a[i+1]==1&&!a[i]&&!a[i+2]){
//                 b.push_back(i);
//             }
//         }
//         for(int i:n)a[i+1]=0;
//         return b;
//     }
// };


// class Solution {
// public:
//     vector<int> findLonely(vector<int>& nums) {
//     unordered_map<int, int> m;
//     vector<int> res;
//     for (int n : nums)
//         ++m[n];
//     for (const auto [n, cnt] : m)
//         if (cnt == 1 && m.count(n + 1) == 0 && m.count(n - 1) == 0)
//             res.push_back(n);
//     return res;  
//     }
// };


class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int& x = nums[i];

            if (mp.count(x - 1)) {
                mp[x - 1]++;
                mp[x]++;
            }

            if (mp.count(x + 1)) {
                mp[x + 1]++;
                mp[x]++;
            }

            mp[x]++;
        }

        for (auto& [num, freq] : mp) {
            if (freq == 1)
                ans.push_back(num);
        }

        return ans;
    }
};
