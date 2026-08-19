// Last updated: 19/08/2026, 15:32:05
class Solution {
public:
    string largestGoodInteger(string num) {
       char c = '0';
       bool a = false;
       for(int i=1; i<num.size()-1; i++){
        if(num[i] == num[i+1] && num[i-1] == num[i]){
            c = max(c,num[i]);
            a = true;
        }
       } 
       if(a == false)return "";
       else{
        string s(3,c);
        return s;
       }
    }
};