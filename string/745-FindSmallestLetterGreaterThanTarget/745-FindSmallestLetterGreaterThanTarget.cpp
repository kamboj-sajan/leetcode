// Last updated: 19/08/2026, 15:57:45
// class Solution {
// public:
//     char nextGreatestLetter(vector<char>& letters, char target) {
//         char ch = letters[0];
//         for(int i=0; i<letters.size(); ++i){
//             if((letters[i] - 'a') > (target - 'a')){
//                 ch = letters[i];
//                 break;
//             }
//         }
//         return ch;
//     }
// };
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int beg = 0;
        int end = letters.size() - 1;
        char ans = letters[0];

        while (beg <= end) {
            int mid =beg+(end-beg)/ 2;

            if (letters[mid] > target) {
                ans = letters[mid];
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }
        return ans;
    }
};