// Last updated: 19/08/2026, 16:06:51
// // class Solution {
// // public:
// //     string reverseWords(string s) {
// //         string str = "";
// //         string temp = "";
// //         for(int i = s.size() - 1; i >= 0; i--) {
// //             if(s[i] == ' ') {
// //                 if(temp.empty()) continue;
// //                 reverse(temp.begin(), temp.end());
// //                 if(!str.empty()) str += ' ';
// //                 str += temp;
// //                 temp.clear();
// //             } else {
// //                 temp += s[i];
// //             }
// //         }
// //         if(!temp.empty()) {
// //             reverse(temp.begin(), temp.end());
// //             if(!str.empty()) str += ' ';
// //             str += temp;
// //         }
// //         return str;
// //     }
// // };

// class Solution {
// public:
//     string reverseWords(string s) {
//         string result = "";
//         int i = s.size()-1;
//         while(i>=0){
//             // Skip spaces
//             while(i>=0 && s[i] == ' '){
//                 i--;
//             }

//             if(i<0) break;

//             int end = i;

//             while(i>=0 && s[i] != ' '){
//                 i--;
//             }

//             // Extract current word
//             string word = s.substr(i+1, end - i);

//             // Add space before appending next word if !result.empty()
//             if(!result.empty()){
//                 result += " ";
//             }

//             result += word;
//         }
//         return result;
//     }
// };

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        
        for(int i = n - 1; i >= 0; ) {
            while(i >= 0 && s[i] == ' ') i--;
            if(i < 0) break;
            
            int j = i;
            while(j >= 0 && s[j] != ' ') j--;
            
            if(!ans.empty()) ans += ' ';
            ans += s.substr(j + 1, i - j);
            
            i = j - 1;
        }
        
        return ans;
    }
};