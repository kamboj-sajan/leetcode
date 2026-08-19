// Last updated: 19/08/2026, 15:33:34
// class Solution {
// public:
//     string decodeCiphertext(string encodedText, int rows) {
//         int cols = encodedText.size()/rows;
//         vector<vector<char>> mat(rows,vector<char>(cols,' '));
//         int ind = 0;
//         for(int i=0; i<rows; ++i){
//             for(int j=0; j<cols; ++j){
//                 mat[i][j] = encodedText[i*cols + j];
//             }
//         }
        // string ans = "";
        // for(int stcol = 0; stcol <= cols; ++stcol){
        //     int i = 0;
        //     int j = stcol;
        //     while(i<rows && j < cols){
        //         ans += mat[i][j];
        //         i++;
        //         j++;
        //     }
        // }
        // while(!ans.empty() && ans.back() == ' '){
        //     ans.pop_back();
        // }
        // return ans;
//     }
// };

// class Solution {
// public:
//     string decodeCiphertext(string encodedText, int rows) {
//         int cols = encodedText.size()/rows;
//         string ans = "";
//         for(int stcol = 0; stcol <= cols; ++stcol){
//             int i = 0;
//             int j = stcol;
//             while(i<rows && j < cols){
//                 ans += encodedText[i*cols + j];
//                 i++;
//                 j++;
//             }
//         }
//         while(!ans.empty() && ans.back() == ' '){
//             ans.pop_back();
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     string decodeCiphertext(string encodedText, int rows) {
//         if (rows == 1) return encodedText;
//         int n = encodedText.size();
//         int cols = n / rows;
//         string ans = "";
//         for (int start = 0; start < cols; start++) {
//             int idx = start;

//             while (idx < n) {
//                 ans += encodedText[idx];
//                 idx += cols + 1;   // 🔥 diagonal jump
//             }
//         }
//         // remove trailing spaces
//         while (!ans.empty() && ans.back() == ' ')
//             ans.pop_back();

//         return ans;
//     }
// };

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if (rows == 1)
            return encodedText;

        int cols = n / rows;
        string res;
        res.reserve(n);

        for (int c = 0; c < cols; ++c) {
            int r = 0, j = c;
            while (r < rows && j < cols) {
                res += encodedText[r * cols + j];
                ++r;
                ++j;
            }
        }

        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }

        return res;
    }
};