// Last updated: 25/09/2026, 01:13:22
// class Solution {
// public:
//    void f(vector<int> &lps,string &s){
//         int n = s.size();
//         int len = 0;
//         int i = 1;
//         while(i < n){
//             if(s[i] == s[len]){
//                 len++;
//                 lps[i] = len;
//                 i++;
//             }else{
//                 if(len == 0){
//                     i++;
//                 }else{
//                     len = lps[len-1];
//                 }
//             }
//         }
//    }
// public:
//     string longestPrefix(string s) {
//         int n = s.size();
//         if(n == 0)return "";
//         vector<int> lps(n,0);
//         f(lps,s);
//         return s.substr(0,lps[n-1]);
//     }
// };

class Solution {
public:
    string longestPrefix(string s) {
        vector<int> arr ( s.size()  , 0  );
        int left = 0;
        int right = 1; 
        while( right < s.size() ){
            if( s[left] == s[right] ){
                arr[right] = left + 1;
                left++; 
                right++;
            }else{
                if( left != 0 ){
                    left = arr[left -1];
                }else{
                    arr[right] = 0; 
                    right++;
                }
            }
        }
        int len = arr[arr.size()- 1];

        return s.substr( 0 , len );
    }
};
