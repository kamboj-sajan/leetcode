// Last updated: 19/08/2026, 16:02:22
// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//         unordered_map<int,int> mpp;
//         for(int i=0;i<s.size(); ++i)mpp[s[i]-'a']++;
//         for(int i=0; i<t.size(); ++i)mpp[t[i] - 'a']++;
//         for(auto &p : mpp){
//             if(p.second%2 == 1)return (p.first + 'a');
//         }
//         return -1;
//     }
// };

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> freq;

        for(int i=0; i<s.length(); i++){
            freq[s[i]]++;
        }

        for(int j=0; j<t.length(); j++){
            if(freq[t[j]] == 0){
                return t[j];
            }
            freq[t[j]]--;
        }

        return ' ';
    }
};