// Last updated: 19/08/2026, 16:10:49
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       int n = digits.size();
       bool a = true;
       for(int i=0; i<n; ++i){
        if(digits[i] != 9){
            a = false;
            break;
        }
       }
       if(a == true){
       if(digits[n-1] == 9){
        int el = n-1;
        for(int i=n-1; i>=0; --i){
            if(digits[i] != 9)break;
            else{
                el = i;
            }
        }
        if(el == n-1){
        digits[n-1] = 1;
        digits.push_back(0);
        }else{
            digits[el] = 1;
            for(int i=el+1; i<=n-1; ++i)digits[i] = 0;
            digits.push_back(0);
        }
       }else{
        digits[n-1] = digits[n-1] + 1;
       }}
       else{
        if(digits[n-1] == 9){
            int a = n-1;
            for(int i=n-1; i>=0; --i){
                if(digits[i] != 9)break;
            else{
                a = i;
                digits[i] = 0;
            }
            }
            digits[a-1] = digits[a-1]+1;
        }else{
            digits[n-1] = digits[n-1] + 1;
        }
       }
       return digits;
    }
};