// Last updated: 13/10/2026, 10:58:31
class Solution {
public:
    int lastRemaining(int n) {
       int head = 1;
       int step =1 ;
       bool l = true;
       int rem = n;
       while(rem > 1){
        if(l || rem%2 == 1){
            head += step;
        }
        rem /= 2;
        step *= 2;
        l = !l;
       } 
       return head;
    }
};