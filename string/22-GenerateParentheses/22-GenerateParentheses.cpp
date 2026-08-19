// Last updated: 19/08/2026, 16:13:18
// class Solution {
//     void f(int i, int j, vector<string> &ans,int n,string temp){
//         if(temp.size() == 2*n){
//             ans.push_back(temp);
//             return;
//         }
//         if(i<n){
//             temp.push_back('(');
//             f(i+1,j,ans,n,temp);
//             temp.pop_back();
//         }
//         if(i>j && j<n){
//             temp.push_back(')');
//             f(i,j+1,ans,n,temp);
//             temp.pop_back();
//         }
//     }
// public:
//     vector<string> generateParenthesis(int n) {
//         vector<string> ans;
//         string temp = "";
//         f(0,0,ans,n,temp);
//         return ans;
//     }
// };

class Solution {
public:
    void f(int i, int j, vector<string> &ans,int n,string temp){
        if(i+j == 2*n){
            ans.push_back(temp);
            return;
        }
        if(i<n){
            f(i+1,j,ans,n,temp + '(');
        }
        if(i>j && j<n){
            f(i,j+1,ans,n,temp + ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        f(0,0,ans,n,temp);
        return ans;
    }
};