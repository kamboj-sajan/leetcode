// Last updated: 19/08/2026, 15:46:56
class Solution {
public:
    int countOdds(int low, int high) {
        if(low == high){
            if(low%2 == 1)return 1;
            else return 0;
        }
        if(low%2 == 0)low++;
        if(high%2 == 0)high--;
       int a = abs((high-low)/2); 
       if(low%2 == 1)a++;
       return a;
    }
};