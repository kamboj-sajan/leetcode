// Last updated: 25/09/2026, 01:21:57
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         int n = s.size();
//         int m = p.size();
//         if(m > n)return {};
//         vector<int> a(26,0);
//         vector<int> b(26,0);
//         for(int i = 0; i<m; i++){
//             b[p[i] - 'a']++;
//             a[s[i] - 'a']++;
//         }
//         vector<int> vec;
//         if(a == b)vec.push_back(0);
//         for(int i=m; i<n; i++){
//             a[s[i] - 'a']++;
//             a[s[i - m] - 'a']--;
//             if(a == b)vec.push_back(i-m+1);
//         }
//         return vec;
//     }
// };

class Solution {
public:
    vector<int> findAnagrams(string &s, string &p) {
        vector<int> ans;
        vector<int> pp(26);
        for(char c : p) pp[c - 'a']++;
        int l = 0, r = 0;
        vector<int>curr(26);
        while(r < p.size()-1 && r < s.size()) curr[s[r++] - 'a']++;
        while(r < s.size()){
            curr[s[r++] - 'a']++;
            bool check = true;
            for(int i=0; i<26; i++){
                if(pp[i] != curr[i]){
                    check = false;
                    break;
                }                
            }
            if(check) ans.push_back(l);
            curr[s[l++] - 'a']--;
        }
        return ans;
    }
};