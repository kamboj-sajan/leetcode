// Last updated: 25/09/2026, 01:13:14
class Solution {
public:
    string ans = "";
    int cnt = 0;

    void solve(string &cur, int n, int k){
        if(cur.size() == n){
            cnt++;
            if(cnt == k) ans = cur;
            return;
        }

        for(char ch : {'a','b','c'}){
            if(cur.empty() || cur.back() != ch){
                cur.push_back(ch);
                solve(cur, n, k);
                cur.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        string cur = "";
        solve(cur, n, k);
        return ans;
    }
};