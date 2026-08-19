// Last updated: 19/08/2026, 16:04:43
class Solution {
public:
    void f(int k, int n, int i,vector<int> &temp,vector<vector<int>> &ans){
        if(k==0 && n == 0){
            ans.push_back(temp);
            return;
        }
        if (k == 0 || n < 0) return;
        for(int j=i; j<=9; j++){
            temp.push_back(j);
            f(k-1,n-j,j+1,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        f(k,n,1,temp,ans);
        return ans;
    }
};