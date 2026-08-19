// Last updated: 19/08/2026, 15:15:49
class Solution {
public:
    vector<string> ans;
    void f(int i,int n,int k,int ct,string &s){
        if(ct > k)return ;
        if(i == n){
            ans.push_back(s);
            return;
        }
        s.push_back('0');
        f(i+1,n,k,ct,s);
        s.pop_back();
        if(i == 0 || s.back() != '1'){
            s.push_back('1');
            f(i+1,n,k,ct+i,s);
            s.pop_back();
        }
    }
public:
    vector<string> generateValidStrings(int n, int k) {
       string s;
        f(0,n,k,0,s);
        return ans;
    }
};