// Last updated: 19/08/2026, 15:38:20
// class Solution {
// public:
//     int maxLengthBetweenEqualCharacters(string s) {
//        int maxi = -1;
//        int n = s.size();
//        for(int i=0; i<n; ++i){
//         for(int j=i+1; j<n; ++j){
//             if(s[i] == s[j]){
//                 maxi = max(maxi,j-i-1);
//             }
//         }
//        }
//        return maxi;
//     }
// };

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxlen = -1;
        vector<int>first(26,-1);
        for(int i = 0; i<s.length();i++){
          int idx = s[i]-'a';
           
           if(first[idx] == -1){
            first[idx] =i;
           }
           else {
             int len = i - first[idx] - 1;
             maxlen = max(maxlen,len);
           }
            }
        return maxlen;
    }
};