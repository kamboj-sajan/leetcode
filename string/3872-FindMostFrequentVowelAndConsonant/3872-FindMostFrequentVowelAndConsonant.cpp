// Last updated: 19/08/2026, 15:24:24
// class Solution {
// public:
//     int maxFreqSum(string s) {
//        unordered_map<char,int> mpp;
//        for(int i=0; i<s.size(); ++i){
//         mpp[s[i]]++;
//        } 
//        int maxi1 = 0;
//        int maxi2 = 0;
//        for(auto &p : mpp){
//         if(p.first == 'a' || p.first == 'e' || p.first == 'i' || p.first == 'o' || p.first == 'u'){
//             maxi1 = max(maxi1,p.second);
//         }else{
//             maxi2 = max(maxi2,p.second);
//         }
//        }
//        return maxi1+maxi2;
//     }
// };

class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26], maxVowel = 0, maxConso = 0;
        for (char c : s) {
            int i = c - 'a';
            freq[i]++;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                maxVowel = max(maxVowel, freq[i]);
            }
            else {
                maxConso = max(maxConso, freq[i]);
            }
        }
        return maxVowel + maxConso;
    }
};