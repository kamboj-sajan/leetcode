// Last updated: 19/08/2026, 15:15:38
class Solution {
public:
    int passwordStrength(string password) {
        int ans = 0;
        unordered_set<char> st;
        for(char c : password){
            if(st.find(c) != st.end()){
            continue;
            }
            st.insert(c);
            if(c >='a' && c <= 'z'){
               ans += 1;
            }else if(c>='A' && c<='Z'){
            ans += 2;
            }else if(c>='0' && c<='9'){
            ans += 3;
            }else {
            ans += 5;
            }
        }
    return ans;
    }
};