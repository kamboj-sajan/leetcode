// Last updated: 11/10/2026, 08:12:49
// class Solution {
// public: 
//     vector<vector<int>> ans;
//     void f(int i,vector<int> &nums,vector<int> temp){
//         if(i == nums.size()){
//             ans.push_back(temp);
//             return;
//         }
//         temp.push_back(nums[i]);
//         f(i+1,nums,temp);
//         temp.pop_back();
//         f(i+1,nums,temp);
//     }
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int> temp;
//         f(0,nums,temp);
//         return ans;
//     }
// };

class Solution {
public:
void back(vector<int> & current,vector<int>& nums,vector<vector<int>> & result,int i){
    if(i==nums.size()){
        result.push_back(current);
        return;
    }
    current.push_back(nums[i]);
    back(current,nums,result,i+1);
    current.pop_back();
    back(current,nums,result,i+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        int i=0;
        back(current,nums,result,i);
        return result;
    }
};