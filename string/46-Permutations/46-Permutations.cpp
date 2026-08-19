// Last updated: 19/08/2026, 16:11:57
// class Solution {
// public:
//     void f(vector<int> &nums,vector<vector<int>> &ans,vector<int> &temp,vector<int> &freq){
//         if(temp.size() == nums.size()){
//             ans.push_back(temp);
//             return;
//         }
//         for(int i=0; i<nums.size(); i++){
//             if(!freq[i]){
//                 temp.push_back(nums[i]);
//                 freq[i] = 1;
//                 f(nums,ans,temp,freq);
//                 freq[i] = 0;
//                 temp.pop_back();
//             }
//         }
//     }
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> temp;
//         vector<vector<int>> ans;
//         vector<int> freq(n,0);
//         f(nums,ans,temp,freq);
//         return ans;
//     }
// };


class Solution {
public:
    void f(vector<int> &nums,vector<vector<int>> &ans,int index){
       if(index == nums.size()){
        ans.push_back(nums);
        return;
       }
       for(int i=index; i<nums.size(); i++){
        swap(nums[index],nums[i]);
        f(nums,ans,index+1);
        swap(nums[index],nums[i]);
       }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
       f(nums,ans,0);
       return ans;
    }
};