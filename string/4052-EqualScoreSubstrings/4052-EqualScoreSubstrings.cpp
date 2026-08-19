// Last updated: 19/08/2026, 15:20:55
class Solution {
public:
    bool scoreBalance(string s) {
       int n = s.size();
        vector<int> a1;
        vector<int> a2;
        int st = 0;
        for(int i=0; i<n; ++i){
            st += s[i] - 'a' + 1;
            a1.push_back(st);
        }
        st = 0;
        for(int i=n-1; i>=0; --i){
            st += s[i] - 'a' + 1;
            a2.push_back(st);
        }
        reverse(a2.begin(),a2.end());
        for(int i=0; i<n-1; ++i){
            if(a1[i] == a2[i+1]){
                return true;
            }
        }
        return false;
    }
};