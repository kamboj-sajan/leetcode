// Last updated: 19/08/2026, 15:32:53
// // // class Solution {
// // // public:
// // //     int minSwaps(vector<int>& nums) {
// // //         int n = nums.size();
// // //         int cnt1 = 0;
// // //         for(int i=0; i<n; i++){
// // //             if(nums[i] == 1)cnt1++;
// // //         }
// // //         if(cnt1 == 0)return 0;
// // //         vector<int> temp = nums;
// // //         temp.insert(temp.end(),nums.begin(),nums.end());
// // //         int n1 = temp.size();
// // //         int mini = INT_MAX;
// // //         int ct0 = 0;
// // //         for(int i=0; i<cnt1; i++){
// // //            if(temp[i] == 0)ct0++;
// // //         }
// // //         int l = 0;
// // //         int r = cnt1-1;
// // //         while(l<n){
// // //             mini = min(mini,ct0);
// // //             if(temp[l] == 0)ct0--;
// // //             l++;
// // //             r++;
// // //             if(temp[r] == 0)ct0++;
// // //         }
// // //         return mini;
// // //     }
// // // };

// // class Solution {
// // public:
// //     int minSwaps(vector<int>& nums) {
// //         int n = nums.size();

// //         int cnt1 = 0;
// //         for(int i = 0; i < n; i++){
// //             if(nums[i] == 1) cnt1++;
// //         }

// //         if(cnt1 == 0 || cnt1 == n) return 0;

// //         vector<int> temp = nums;
// //         temp.insert(temp.end(), nums.begin(), nums.end());

// //         int mini = INT_MAX;
// //         int ct0 = 0;

// //         for(int i = 0; i < cnt1; i++){
// //             if(temp[i] == 0) ct0++;
// //         }

// //         int l = 0;
// //         int r = cnt1;

// //         while(l < n){
// //             mini = min(mini, ct0);

// //             if(temp[l] == 0) ct0--;

// //             if(temp[r] == 0) ct0++;

// //             l++;
// //             r++;
// //         }

// //         return mini;
// //     }
// // };

// class Solution {
// public:
//     int minSwaps(vector<int>& nums) {
//         int n = nums.size();

//         int cnt1 = 0;
//         for(int x : nums){
//             cnt1 += x;
//         }

//         if(cnt1 == 0 || cnt1 == n) return 0;

//         int cnt0 = 0;

//         // First window of size cnt1
//         for(int i = 0; i < cnt1; i++){
//             if(nums[i] == 0) cnt0++;
//         }

//         int ans = cnt0;

//         // Slide the window circularly
//         for(int i = 1; i < n; i++){
//             if(nums[i - 1] == 0) cnt0--;

//             if(nums[(i + cnt1 - 1) % n] == 0) cnt0++;

//             ans = min(ans, cnt0);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int one = 0;
        for (int num : nums) {
            one += num;
        }
        if (one == 0 || one == n) return 0;
        int currOne = 0;
        for (int i = 0; i < one; i++) {
            currOne += nums[i];
        }
        int maxOnes = currOne;
        for (int i = 0; i < n; i++) {
            currOne -= nums[i];
            currOne += nums[(i + one) % n];
            maxOnes = max(maxOnes, currOne);
        }
        return one - maxOnes;
    }
};