// Last updated: 19/08/2026, 16:03:47
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.size() != t.size())return false;
//         unordered_map<char,int> mpp;
//         unordered_map<char,int> mpp2;
//         for(int i=0; i<s.size(); i++){
//             mpp[s[i]]++;
//             mpp2[t[i]]++;
//         }
//         for(auto &p : mpp){
//             if(mpp[p.first] != mpp2[p.first])return false; 
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> counts = vector<int>(26);
        for(char&c: s){
            counts[c-'a']++;
        }
        for(char&c: t){
            counts[c-'a']--;
        }
        for(int i=0;i<26;i++){
            if(counts[i] != 0)
                return false;
        }
        return true;
    }
};