// Last updated: 19/08/2026, 15:56:08
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        int n = bills.size();
        for(int i=0; i<n; i++){
            if(bills[i] == 20){
                if(five && ten){
                    ten -= 1;
                    five -= 1;
                }else if(five >= 3){
                    five -= 3;
                }else{
                    return false;
                }
            }else if(bills[i] == 10){
               if(five){
                ten += 1;
                five -= 1;
               }else{
                return false;
               }
            }else{
                five++;
            }
        }
        return true;
    }
};