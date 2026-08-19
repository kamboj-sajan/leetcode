// Last updated: 19/08/2026, 15:34:11
// class Solution {
// public:
//     int maxConsecutiveAnswers(string answerKey, int k) {
//         int n = answerKey.size();
//         int ans = INT_MIN;
//         for(int i=0; i<2; ++i){
//         char a;
//         if(i == 0)a = 'T';
//         else a = 'F';
//         int ct =0;
//         int l = 0, r= 0;
//         while(r < n){
//             if(answerKey[r] != a){
//                 ct++;
//                 while(ct > k){
//                     if(answerKey[l] != a)ct--;
//                     l++;
//                 }
//             }
//             ans = max(ans,r-l+1);
//             r++;
//         }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int maxConsecutiveAnswers(string s, int k) {
//         int hm = 0;
//         int n = s.size();
//         int left = 0, right = 0;
//         int Tc = 0, Fc = 0;
//         while (right < n) {
//             s[right] == 'T' ? Tc++ : Fc++;

//             while ((right - left + 1 - max(Tc, Fc)) > k) {
//                 s[left] == 'T' ? Tc--: Fc--;
//                 left++;
//             }
//             hm = max(right - left + 1, hm);
//             right++;
//         }
//         return hm;
//     }
// };

class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int l = 0, ans = 0;
        int cntT = 0, cntF = 0;

        for(int r = 0; r < s.size(); r++) {
            if(s[r] == 'T') cntT++;
            else cntF++;

            while((r - l + 1) - max(cntT, cntF) > k) {
                if(s[l] == 'T') cntT--;
                else cntF--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};