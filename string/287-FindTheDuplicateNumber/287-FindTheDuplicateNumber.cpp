// Last updated: 11/10/2026, 08:11:06
// // class Solution {
// // public:
// //     int findDuplicate(vector<int>& nums) {
// //         unordered_map<int,int> mpp;
// //         for(int i : nums){
// //             mpp[i]++;
// //             if(mpp[i] >1 )return i;
// //         }
// //         return -1;
// //     }
// // };

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//     int index=0,i=0;
//     while(nums[index] != -1){
//         index = nums[i];
//         nums[i]= -1;
//         i=index;
//     }
//     return index;
//     }
// };

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};