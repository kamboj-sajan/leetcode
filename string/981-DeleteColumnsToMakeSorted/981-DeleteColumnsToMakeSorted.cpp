// Last updated: 19/08/2026, 15:55:05
// class Solution {
// public:
//     int minDeletionSize(vector<string>& strs) {
//         int rows = strs.size();
//         int cols = strs[0].size();
//         int cnt = 0;
//         for (int col = 0; col < cols; ++col) {
//             for (int row = 1; row < rows; ++row) {
//                 if (strs[row - 1][col] > strs[row][col]) {
//                     cnt++;
//                     break;
//                 }
//             }
//         }
//         return cnt;
//     }
// };

// class Solution {
// public:
//     int minDeletionSize(vector<string>& strs) {
//         int n=strs.size();
//         int count=0;
//         int k=strs[0].length();
//         for(int i=0;i<k;i++){
//             for(int j=1;j<n;j++){
//                 if(strs[j][i] < strs[j-1][i]){
//                     count++;
//                     break;
//                 }
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            bool sorted=is_sorted(strs.begin(),strs.end(),[i](const string &a, const string &b){return a[i]<b[i];});
            if(!sorted) cnt++;
        }
        return cnt;
    }
};