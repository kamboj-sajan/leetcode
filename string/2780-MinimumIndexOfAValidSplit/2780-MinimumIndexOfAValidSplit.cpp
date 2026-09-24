// Last updated: 25/09/2026, 01:03:21
// // class Solution {
// // public:
// //     int minimumIndex(vector<int>& nums) {
// //         int n = nums.size();
// //         unordered_map<int,int> mpp;
// //         for(int i : nums){
// //             mpp[i]++;
// //         }
// //         unordered_map<int,int> mpp2;
// //         int el = -1;
// //         for(int i=0; i<n-1; i++){
// //             if(i == 0){
// //                 el = nums[i];
// //                 mpp2[nums[i]]++;
// //                 mpp[nums[i]]--;
// //                 if(mpp2[el]*2 > (i+1) && mpp[el]*2 > (n-i-1))return i;
// //             }else{
// //                 mpp2[nums[i]]++;
// //                 mpp[nums[i]]--;
// //                 if(mpp2[nums[i]] > mpp2[el])el = nums[i];
// //                 if(mpp2[el]*2 > (i+1) && mpp[el]*2 > (n-i-1))return i;
// //             }
// //         }
// //         return -1;
// //     }
// // };

// class Solution {
// public:
//     int minimumIndex(vector<int>& nums) {
//         int n=nums.size();
//         int vote=1;
//         int val=nums[0];
//         for(int i=1;i<n;i++){
//             if(val==nums[i]){
//                 vote++;
//             }else{
//                 vote--;
//                 if(vote<0){
//                     val=nums[i];
//                     vote=1;
//                 }
//             }
//         }
//         int fre=0;
//         for(int i=0;i<n;i++){
//             if(nums[i]==val)fre++;
//         }
//         int count=0;
//         for(int i=0;i<n;i++){
//             int l=i+1;
//             int r=n-l;
//             if(nums[i]==val){
//                 count++;
//                 fre--;
//             }
//             if(count>(l/2)&&fre>(r/2))return i;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find the dominant element
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        int dominant = -1;

        for (auto &[x, count] : freq) {
            if (count * 2 > n) {
                dominant = x;
                break;
            }
        }

        // Step 2: Check every possible split
        int leftCount = 0;
        int totalCount = freq[dominant];

        for (int i = 0; i < n - 1; i++) {

            if (nums[i] == dominant) {
                leftCount++;
            }

            int leftSize = i + 1;
            int rightSize = n - i - 1;

            int rightCount = totalCount - leftCount;

            // dominant must be dominant on both sides
            if (leftCount * 2 > leftSize &&
                rightCount * 2 > rightSize) {
                return i;
            }
        }

        return -1;
    }
};