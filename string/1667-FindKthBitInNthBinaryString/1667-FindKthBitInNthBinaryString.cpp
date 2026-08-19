// Last updated: 19/08/2026, 15:46:27
// class Solution {
// public:
//     char findKthBit(int n, int k) {
//         string s1 = "0";
//         string s2;

//         for(int i = 2; i <= n; ++i){
//             s2 = s1 + "1";

//             string temp = s1;                 // use temp instead of modifying s1
//             reverse(temp.begin(), temp.end());

//             for(char &c : temp){              // invert
//                 c = (c == '0') ? '1' : '0';
//             }

//             s2 += temp;
//             s1 = s2;
//         }

//         return s1[k - 1];   // k is 1-based
//     }
// };

class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";

        for (int i = 2; i <= n; i++) {
            string temp = s;
            reverse(temp.begin(), temp.end());

            // invert
            for (char &c : temp) {
                c = (c == '0') ? '1' : '0';
            }

            s = s + "1" + temp;
        }

        return s[k - 1];   // k is 1-based
    }
};
// //optimal
// class Solution {
// public:
//     char findKthBit(int n, int k) {
//         if (n == 1) return '0';

//         int length = (1 << n) - 1;
//         int mid = length / 2 + 1;

//         if (k == mid) return '1';
//         else if (k < mid)
//             return findKthBit(n - 1, k);
//         else {
//             char ch = findKthBit(n - 1, length - k + 1);
//             return (ch == '0') ? '1' : '0';
//         }
//     }
// };