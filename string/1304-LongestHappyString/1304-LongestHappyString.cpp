// Last updated: 19/08/2026, 15:51:18
// class Solution {
// public:
//     string longestDiverseString(int a, int b, int c) {
//         priority_queue<pair<int,char>> pq;
//         if (a) pq.push({a,'a'});
//         if (b) pq.push({b,'b'});
//         if (c) pq.push({c,'c'});
//         string ans;
//         while (!pq.empty()) {
//             auto [cnt1,ch1] = pq.top();
//             pq.pop();
//             int n = ans.size();
//             if (n >= 2 && ans[n-1] == ch1 && ans[n-2] == ch1) {
//                 if (pq.empty()) break;
//                 auto [cnt2,ch2] = pq.top();
//                 pq.pop();
//                 ans += ch2;
//                 cnt2--;
//                 if (cnt2 > 0) pq.push({cnt2,ch2});
//                 pq.push({cnt1,ch1});
//             }
//             else {
//                 ans += ch1;
//                 cnt1--;
//                 if (cnt1 > 0) pq.push({cnt1,ch1});
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int curra = 0, currb = 0, currc = 0;
        // Maximum total iterations possible is given by the sum of a, b and c.
        int totalIterations = a + b + c;
        string ans = "";

        for (int i = 0; i < totalIterations; i++) {
            if ((a >= b and a >= c and curra != 2) or
                (a > 0 and (currb == 2 or currc == 2))) {
                // If 'a' is maximum and it's streak is less than 2, or if
                // streak of 'b' or 'c' is 2, then 'a' will be the next
                // character.
                ans += 'a';
                a--;
                curra++;
                currb = 0;
                currc = 0;
            } else if ((b >= a and b >= c and currb != 2) or
                       (b > 0 and (currc == 2 or curra == 2))) {
                // If 'b' is maximum and it's streak is less than 2, or if
                // streak of 'a' or 'c' is 2, then 'b' will be the next
                // character.
                ans += 'b';
                b--;
                currb++;
                curra = 0;
                currc = 0;
            } else if ((c >= a and c >= b and currc != 2) or
                       (c > 0 and (curra == 2 or currb == 2))) {
                // If 'c' is maximum and it's streak is less than 2, or if
                // streak of 'a' or 'b' is 2, then 'c' will be the next
                // character.
                ans += 'c';
                c--;
                currc++;
                curra = 0;
                currb = 0;
            }
        }
        return ans;
    }
};