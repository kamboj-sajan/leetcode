// Last updated: 19/08/2026, 16:09:51
// class Solution {
// public:
//     void f(vector<int> &nums,int i,set<vector<int>> &ans,vector<int> &temp){
//         if(i==nums.size()){
//             ans.insert(temp);
//             return;
//         }
//         temp.push_back(nums[i]);
//         f(nums,i+1,ans,temp);
//         temp.pop_back();
//         f(nums,i+1,ans,temp);
//     }
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         set<vector<int>> ans;
//         vector<int> temp;
//         f(nums,0,ans,temp);
//         vector<vector<int>> result(ans.begin(), ans.end());
//        return result; 
//     }
// };

class Solution {
public:
    void f(vector<int> &nums,int i,vector<vector<int>> &ans,vector<int> &temp){
    //    if(i==nums.size()){
    //     ans.push_back(temp);
    //     return;
    //    }
    //    temp.push_back(nums[i]);
    //     f(nums,i+1,ans,temp);
    //    if(i>0){
    //     for(int j=i; nums[j] != nums[j-1]; j++){
    //         i++;
    //     }
    //    }
    //    temp.pop_back();
    //    f(nums,i+1,ans,temp);
    // 2/20 testcases
     ans.push_back(temp);
        for (int j = i; j < nums.size(); ++j) {
            if (j > i && nums[j] == nums[j - 1]) continue; // skip duplicates
            temp.push_back(nums[j]);
            f(nums, j + 1, ans, temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        f(nums,0,ans,temp);
       return ans; 
    }
};