// Last updated: 19/08/2026, 16:12:16
class Solution {
public:
   void f(vector<int>& arr, int target, int i, vector<int>& ans, vector<vector<int>>& t) {
        if (target == 0) {

            t.push_back(ans);
            return;
        }
        if (i == arr.size() || target < 0) return;
        
        ans.push_back(arr[i]);
        f(arr, target - arr[i], i+1, ans, t); 
        ans.pop_back(); 
        while (i + 1 < arr.size() && arr[i] == arr[i + 1]) i++;
        

        f(arr, target, i + 1, ans, t);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> t;
        sort(candidates.begin(),candidates.end());
        f(candidates,target,0,ans,t);
        return t;
    }
};



// class Solution{
// public:
//    void f(vector<int>& arr, int target, int ind, vector<int>& ans, vector<vector<int>>& t) {
//         if (target == 0) {

//             t.push_back(ans);
//             return;
//         }
//         for(int i=ind; i<arr.size(); i++){
//             if(i>ind && arr[i] == arr[i-1])continue;
//             if(arr[i] > target)break;
//             ans.push_back(arr[i]);
//             f(arr,target-arr[i],i+1,ans,t);
//             ans.pop_back();
//         }
//     }
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         vector<int> ans;
//         vector<vector<int>> t;
//         sort(candidates.begin(),candidates.end());
//         f(candidates,target,0,ans,t);
//         return t;
//     }
// };