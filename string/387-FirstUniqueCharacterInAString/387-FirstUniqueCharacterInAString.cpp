// Last updated: 19/08/2026, 16:02:26
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        vector<int> frq(26,0);
        for(char c : s){
            frq[c - 'a']++;
        }
        for(int i=0; i<n; ++i){
            if(frq[s[i] - 'a'] == 1)return i;
        }
        return -1;
    }
};