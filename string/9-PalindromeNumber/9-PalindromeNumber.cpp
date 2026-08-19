// Last updated: 19/08/2026, 16:14:01
class Solution {
public:
    bool isPalindrome(int x) {
        int dup = x;
        long revN = 0;
        while(x>0){
            int lastdigit = x%10;
            x = x/10;
            revN = (revN*10)+lastdigit;
        }
        
        if(revN == dup){
            return true;
        }else{
            return false;
        }
        
    }
};