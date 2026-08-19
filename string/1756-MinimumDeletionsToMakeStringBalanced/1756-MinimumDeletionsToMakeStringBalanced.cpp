// Last updated: 19/08/2026, 15:38:07
// class Solution {
// public:
//     int minimumDeletions(string s) {
//         int n = s.size();
//         vector<pair<int,int>> vec;
//         int a = 0;
//         int b = 0;
//         for(int i=0; i<n; ++i){
//             if(s[i] == 'a')a++;
//         }
//         int mini = INT_MAX;
//         for(int i=0; i<n; ++i){
//             if(s[i] == 'b'){
//                 b++;
//             }
//             mini = min(mini,a+b);
//             if(s[i] == 'a'){
//                 a--;
//             }
//         }
//         return mini-1;
//     }
// };

// class Solution {
// public:
//     int minimumDeletions(string s) {
//         int bCount = 0;     // number of 'b' seen so far
//         int deletions = 0;  // minimum deletions

//         for(char c : s) {
//             if(c == 'b') {
//                 bCount++;
//             } else { // c == 'a'
//                 if(bCount > 0) {
//                     deletions++;
//                     bCount--;   // delete one previous 'b'
//                 }
//             }
//         }
//         return deletions;
//     }
// };

class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        int bcount=0;
        int deletion=0;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                bcount++;
            }
            else{//if s[i]=='a'
                deletion=min(deletion+1,bcount);
            }
        }
        return deletion;
    }
};