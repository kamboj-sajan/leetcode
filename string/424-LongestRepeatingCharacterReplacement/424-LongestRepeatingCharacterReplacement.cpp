// Last updated: 19/08/2026, 16:01:42
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int n = s.size();
//         int ans = INT_MIN;
//         for(int i=0; i<26; ++i){
//             int ct = 0;
//             int l = 0;
//             int r = 0;
//             while(r < n){
//                 if((s[r]-'A') != i){
//                     ct++;
//                     while(ct > k){
//                         if((s[l] - 'A') != i)ct--;
//                         l++;
//                     }
//                 }
//                 ans = max(ans,r-l+1);
//                 r++;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> count(26, 0);
        int n = s.size();

        int i = 0;
        int j = 0;
        int size = 0;

        int maxFreq = 0;

        while (j < n) {
            int ch = s[j] -'A';
            count[ch]++;
            maxFreq = max(maxFreq, count[ch]);

            while (j - i + 1 - maxFreq > k && i<j) {
                size = max(size, j - i);
                int ch2 = s[i] -'A';
                count[ch2]--;
                maxFreq = 0;
                for (int l = 0; l < 26; l++) {
                    maxFreq = max(maxFreq, count[l]);
                }
                
                i++;
            }
            j++;
        }
        size = max(size,j - i);

        return size;
    }
};

/*
longest substring with
[i,j]-> lenght is j-i+1 = len

a1(f1)a2(f2)....am(fm)

f1+f2+...+fm = len

say max of fs is fx
then  len - fx <=k

*/