// Last updated: 19/08/2026, 15:32:36
// class Solution {
// public:
//     int findFinalValue(vector<int>& nums, int original) {
//         int n = nums.size();
//         int b = original;
//         bool a = true;
//         while(a != false){
//             a = false;
//             for(int i=0; i<n; ++i){
//                 if(b == nums[i]){
//                     b = 2 * b;
//                     a = true;
//                     break;
//                 }
//             }
//             if(a == false){
//                 break;
//             }else continue;
//         }
//         return b;
//     }
// };

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
       bool fnd = true;
       int b = original;
       while(fnd){
        for(vector<int>::const_iterator it = nums.cbegin(); it != nums.cend(); it++){
            if(original == *it){
                b = (original << 1);
                break;
            }
        }
        fnd = (b != original);
        original = b;
       }
       return original;
    }
};