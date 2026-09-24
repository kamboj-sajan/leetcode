// Last updated: 25/09/2026, 01:21:02
// // // class Solution {
// // // public:
// // //     bool f(int i,int bucketnum,int bucketsum,int reqsum,int k,vector<int> &nums,vector<int> &alreadypicked){
// // //         if(bucketnum == k){
// // //             return true;
// // //         }
// // //         if(bucketsum == reqsum){
// // //             return f(0,bucketnum +1,0,reqsum,k,nums,alreadypicked);
// // //         }
// // //         if(bucketsum > reqsum)return false;
// // //         if(i >= nums.size()){
// // //             return false;
// // //         }
// // //         if(alreadypicked[i] == 1){
// // //             return f(i+1,bucketnum,bucketsum,reqsum,k,nums,alreadypicked);
// // //         }else{
// // //             //pick
// // //             bucketsum += nums[i];
// // //             alreadypicked[i] = 1;
// // //             bool p = f(i+1,bucketnum,bucketsum,reqsum,k,nums,alreadypicked);
// // //             //not pick
// // //             bucketsum -= nums[i];
// // //             alreadypicked[i] = 0;
// // //             bool np = f(i+1,bucketnum,bucketsum,reqsum,k,nums,alreadypicked);
// // //             return p || np;
// // //         }
// // //         return false;
// // //     }
// // // public:
// // //     bool canPartitionKSubsets(vector<int>& nums, int k) {
// // //         int n = nums.size();
// // //         int sum = 0;
// // //         for(int i=0; i<n; i++){
// // //             sum += nums[i];
// // //         }
// // //         if(sum%k != 0)return false;
// // //         int rqsum = sum/k;
// // //         vector<int> alreadypicked(n,0);
// // //         return f(0,0,0,rqsum,k,nums,alreadypicked);
// // //     }
// // // };

// // class Solution {
// // public:
// //     vector<vector<vector<vector<int>>>> dp;
// //     bool f(int i, int bucketnum, int bucketsum, int reqsum, int k,
// //            vector<int>& nums, int mask) {
// //         if (bucketnum == k) {
// //             return true;
// //         }
// //         if (bucketsum == reqsum) {
// //             return f(0, bucketnum + 1, 0, reqsum, k, nums, mask);
// //         }
// //         if (bucketsum > reqsum || i >= nums.size()) {
// //             return false;
// //         }
// //         if (dp[i][bucketnum][bucketsum][mask] != -1) {
// //             return dp[i][bucketnum][bucketsum][mask];
// //         }
// //         // already picked
// //         if (mask & (1 << i)) {
// //             return dp[i][bucketnum][bucketsum][mask] =
// //                 f(i + 1, bucketnum, bucketsum, reqsum, k, nums, mask);
// //         }

// //         // pick
// //         mask = mask | (1 << i);

// //         bool p = f(i + 1, bucketnum, bucketsum + nums[i],
// //                    reqsum, k, nums, mask);

// //         // not pick
// //         mask = mask ^ (1 << i);

// //         bool np = f(i + 1, bucketnum, bucketsum,
// //                     reqsum, k, nums, mask);

// //         return dp[i][bucketnum][bucketsum][mask] = p || np;
// //     }

// //     bool canPartitionKSubsets(vector<int>& nums, int k) {

// //         int sum = 0;

// //         for (int x : nums) {
// //             sum += x;
// //         }

// //         if (sum % k != 0) {
// //             return false;
// //         }

// //         int reqsum = sum / k;
// //         int n = nums.size();

// //         dp.resize(n,
// //             vector<vector<vector<int>>>(
// //                 k + 1,
// //                 vector<vector<int>>(
// //                     reqsum + 1,
// //                     vector<int>(1 << n, -1)
// //                 )
// //             )
// //         );

// //         return f(0, 0, 0, reqsum, k, nums, 0);
// //     }
// // };

// class Solution {
// public:
//     vector<int> dp;

//     bool f(int mask, int currSum, int reqsum, int k,
//            vector<int>& nums) {
//         if (k == 1) {
//             return true;
//         }
//         if (currSum == reqsum) {
//             return f(mask, 0, reqsum, k - 1, nums);
//         }
//         if (dp[mask] != -1) {
//             return dp[mask];
//         }
//         for (int i = 0; i < nums.size(); i++) {
//             if (mask & (1 << i)) {
//                 continue;
//             }
//             if (currSum + nums[i] > reqsum) {
//                 continue;
//             }
//             if (f(mask | (1 << i),
//                  currSum + nums[i],
//                  reqsum, k, nums)) {
//                 return dp[mask] = true;
//             }
//         }
//         return dp[mask] = false;
//     }

//     bool canPartitionKSubsets(vector<int>& nums, int k) {

//         int sum = 0;
//         for (int x : nums) {
//             sum += x;
//         }
//         if (sum % k != 0) {
//             return false;
//         }

//         int reqsum = sum / k;

//         dp.resize(1 << nums.size(), -1);

//         return f(0, 0, reqsum, k, nums);
//     }
// };

class Solution {
public:
    bool f(int start, int k, int sum, int reqsum,
           vector<int>& nums, vector<int>& used) {

        if (k == 1) {
            return true;
        }

        if (sum == reqsum) {
            return f(0, k - 1, 0, reqsum, nums, used);
        }

        for (int i = start; i < nums.size(); i++) {

            if (used[i]) continue;

            if (sum + nums[i] > reqsum) continue;

            used[i] = 1;

            if (f(i + 1, k, sum + nums[i],
                  reqsum, nums, used)) {
                return true;
            }

            used[i] = 0;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum = 0;

        for (int x : nums) {
            sum += x;
        }

        if (sum % k != 0) {
            return false;
        }

        int reqsum = sum / k;

        vector<int> used(nums.size(), 0);

        return f(0, k, 0, reqsum, nums, used);
    }
};