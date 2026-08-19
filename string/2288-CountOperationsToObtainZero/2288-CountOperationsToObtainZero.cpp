// Last updated: 19/08/2026, 15:32:32
// class Solution {
// public:
//     int countOperations(int num1, int num2) {
//         int ans = 0;
//         while(num1 >0 && num2 > 0){
//             if(num1 >= num2){
//                 num1 -= num2;
//                 ans++;
//             }else{
//                 num2 -= num1;
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int countOperations(int num1, int num2) {
        int cnt = 0;
        while (num1 && num2) {
            if (num1 < num2) {
                swap(num1, num2);
            }
            cnt += num1 / num2;
            num1 %= num2;
        }
        return cnt;
    }
};