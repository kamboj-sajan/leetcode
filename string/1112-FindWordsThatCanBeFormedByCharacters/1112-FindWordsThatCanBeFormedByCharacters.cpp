// Last updated: 19/08/2026, 15:53:33
// class Solution {
// public:
//     int countCharacters(vector<string>& words, string chars) {
//         int n = chars.size();
//         unordered_map<char,int> mpp;
//         for(int i=0; i<n; ++i)mpp[chars[i]]++;
//         int k = words.size();
//         unordered_map<char,int> temp;
//         int cnt = 0;
//         for(int i=0; i<words.size(); ++i){
//             temp = mpp;
//             bool a = true;
//             for(int j=0; j<words[i].size(); ++j){
//                 if(temp[words[i][j]] == 0){
//                     a = false;
//                     continue;
//                 }
//                 else{
//                     temp[words[i][j]]--;
//                 }
//             }
//             if(a == true)cnt += words[i].size();
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int hashh[26] = {0};
        int count = 0;
        for (int i = 0; i < chars.size(); i++) {
            hashh[chars[i] - 'a']++;
        }
        for (int i = 0; i < words.size(); i++) {
            int hash[26] = {0};
            for (char it : words[i]) {
                hash[it - 'a']++;
            }
            int j;
            for (j = 0; j < 26; j++) {
                if (hash[j] > hashh[j]) break;
            }
            if (j == 26) count += words[i].size();  
        }

        return count;
    }
};