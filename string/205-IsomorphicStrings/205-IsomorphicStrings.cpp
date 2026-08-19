// Last updated: 19/08/2026, 16:05:14
// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         unordered_map<char,char> mpp;
//         unordered_map<char,char> mpp2;
//         if(s.size() != t.size()) return false;
//         for(int i = 0; i < s.size(); i++){
//             if(mpp.find(s[i]) == mpp.end()){
//                 if(mpp2.find(t[i]) != mpp2.end()){
//                     return false;
//                 }
//                 mpp[s[i]] = t[i];
//                 mpp2[t[i]] = s[i];
//             }else{
//                 if(mpp[s[i]] != t[i]){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256]={0},m2[256]={0};
        int n=s.size();
        for (int i=0;i<n;++i)
        {
        if (m1[s[i]]!=m2[t[i]])
        return false;
        m1[s[i]]=i+1;
        m2[t[i]]=i+1;
    }
    return true;
    }
};