// Last updated: 19/08/2026, 16:12:18
class Solution {
public:void f(vector<int>& arr, int target, int i, vector<int>& ans, vector<vector<int>>& t) {
        if (target == 0) {
            t.push_back(ans);
            return;
        }
        if (i == arr.size() || target < 0) return;

        ans.push_back(arr[i]);
        f(arr, target - arr[i], i, ans, t); 
        ans.pop_back(); 
        // put above three lines in condition target < k if you dont want the target to be negative

        f(arr, target, i + 1, ans, t);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> t;
       f(candidates,target,0,ans,t);
       return t;
    }
};