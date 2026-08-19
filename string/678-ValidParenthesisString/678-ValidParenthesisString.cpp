// Last updated: 19/08/2026, 15:58:35
// class Solution {
// public:
//     bool checkValidString(string s) {
//     int n = s.size();
//     int i = 0, j= n - 1;
//     if(n == 1)return false;
//     while(i < j){
//         if(s[i] == '(' || s[i] == '*'){
//             if(s[j] == ')' || s[j] == '*'){
//                 i++;
//                 j--;
//                 continue;
//             }else{
//                 return false;
//             }
//         }else{
//             return false;
//         }
//     }   
//     return true;
//     }
// }; 64/83 test cases
// m1 do with recursion brute force


// value star can take -1, 0 ,1
class Solution {
public:
    bool checkValidString(string s) {
    int n = s.size();
    int min = 0;
    int max = 0;
    for(int i=0; i<n; ++i){
        if(s[i] == '('){
            min++;
            max++;
        }else if(s[i] == ')'){
            min--;
            max--;
        }else{
            min--;
            max++;
        }
        if(min < 0)min = 0;
        if(max < 0)return false;
    }
    return (min == 0);
    }
}; 