// Last updated: 19/08/2026, 15:32:01
// class Solution {
// public:
//     int rearrangeCharacters(string s, string target) {
//         unordered_map<char,int> mpp, mpp2;
//         for(char c : target)mpp[c]++;
//         for(char c : s)mpp2[c]++;
//         int mini = INT_MAX;
//         for(auto &p : mpp){
//             mini = min(mini, mpp2[p.first] / p.second);
//         }
//         return mini;
//     }
// };

// class Solution {
// public:
//     int rearrangeCharacters(string s, string target) {
//         unordered_map<char, int> need, have;
//         for (char c : target) {
//             need[c]++;
//         }
//         for (char c : s) {
//             have[c]++;
//         }
//         int ans = INT_MAX;
//         for (auto &[ch, freq] : need) {
//             ans = min(ans, have[ch] / freq);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> have(26, 0), need(26, 0);

        for (char c : s) have[c - 'a']++;
        for (char c : target) need[c - 'a']++;

        int ans = INT_MAX;

        for (int i = 0; i < 26; i++) {
            if (need[i] > 0) {
                ans = min(ans, have[i] / need[i]);
            }
        }

        return ans;
    }
};