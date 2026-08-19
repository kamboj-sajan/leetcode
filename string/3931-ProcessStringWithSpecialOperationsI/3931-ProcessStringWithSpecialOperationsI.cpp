// Last updated: 19/08/2026, 15:23:39
// class Solution {
// public:
//     string processStr(string s) {
//         string temp = "";
//         for(int i=0; i<s.size(); ++i){
//             if(s[i] == '*'){
//                 if(temp != "")temp.pop_back();
//             }else if(s[i] == '#'){
//                 temp += temp;
//             }else if(s[i] == '%'){
//                 reverse(temp.begin(),temp.end());
//             }else{
//                 temp.push_back(s[i]);
//             }
//         }
//         return temp;
//     }
// };

class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string ans = "";
        for(char c : s){
         if(c >= 'a' && c <= 'z'){
            ans.push_back(c);
         }

         else if(c == '*'){
            if(!ans.empty()) ans.pop_back();
         }
         else if(c=='#'){
            ans+=ans;
         }else if(c == '%'){
            reverse(ans.begin(),ans.end());
         }
        }
        return ans;


    }
};