// Last updated: 25/09/2026, 01:19:57
// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if(s.size() > goal.size())return false;
//         string str = s + s;
//         if(str.find(goal) != string::npos)return true;
//         else return false;
//     }
// };

// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if(s == goal)return true;
//         string ans = "";
//         for(int i=1; i<s.size(); i++){
//            string a = s.substr(i,s.size());
//            string b = s.substr(0,i);
//            ans = a + b;
//            if(ans == goal)return true;
//            ans.clear();
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool rotateString(string s, string goal) {
         if (s.length() != goal.length()) {
            return false;
        }
        return (s + s).find(goal) != string::npos;
    }
};