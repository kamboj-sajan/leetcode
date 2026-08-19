// Last updated: 19/08/2026, 15:25:52
// class Solution {
// public:
//     bool hasSameDigits(string s) {
//         string dup = s;
//         int n = dup.size();
//         if(n < 2) return false; 

//         while(n > 2) {
//             string str = "";
//             for(int i = 0; i < dup.size() - 1; ++i) {
//                 int a = ((dup[i] - '0') + (dup[i + 1] - '0')) % 10;
//                 str += (a + '0');
//             }
//             dup = str;
//             n = dup.size(); 
//         }

//         return dup[0] == dup[1];
//     }
// };


class Solution {
public:
    bool hasSameDigits(string s) {
       while(s.size()>2){
            int idx=0;
            string newS=s;
            while(idx<s.size()-1){
                char n=(s[idx]-'0'+s[idx+1]-'0')%10;
                newS[idx]=n+'0';
                idx++;
            }
            newS.pop_back();
            s=newS;
        }
        return (s[0]==s[1])?true:false;
    }
};