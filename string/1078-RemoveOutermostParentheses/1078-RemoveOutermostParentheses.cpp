// Last updated: 19/08/2026, 15:53:44
// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//        int cnt = 0;
//        string str = "";
//        for(int i=0; i<s.size(); i++){
//         if(s[i] == '(')cnt++;
//         else cnt--;
//         if(cnt == 1 && s[i] == '(')continue;
//         else if(cnt == 0)continue;
//         else str += s[i];
//        }
//        return str;
//     }
// };

class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string str="";
        for(char ch:s){
            if(ch =='('){
                cnt++;
                if(cnt>1)str.push_back(ch);
            }
            else{
                cnt--;
                if(cnt>0)str.push_back(ch);
            }
        }
        return str;
    }
};