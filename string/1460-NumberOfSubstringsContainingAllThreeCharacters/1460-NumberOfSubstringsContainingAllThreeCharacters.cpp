// Last updated: 19/08/2026, 15:49:01
// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
//         int ans = 0;
//         int l = 0;
//         vector<int> freq(3, 0);
//         for (int r = 0; r < n; r++) {
//             freq[s[r] - 'a']++;
//             while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
//                 ans += n - r;

//                 freq[s[l] - 'a']--;
//                 l++;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastseen[3] = {-1,-1,-1};
        int cnt = 0;
        for(int i=0; i<s.size(); i++){
            lastseen[s[i] - 'a'] = i;
            //if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1)
            cnt = cnt + min({lastseen[0],lastseen[1],lastseen[2]}) + 1;
        }
        return cnt;
    }
};