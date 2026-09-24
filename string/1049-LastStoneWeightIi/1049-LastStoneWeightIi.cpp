// Last updated: 25/09/2026, 01:16:57
// class Solution {
// public:
//     int ans;
//     void f(int i,int sum,vector<int> &nums){
//         if(i == nums.size()){
//             if(sum >= 0)ans = min(ans,sum);
//             return;
//         }
//         f(i+1,sum + nums[i],nums);
//         f(i+1,sum-nums[i],nums);
//     }
// public:
//     int lastStoneWeightII(vector<int>& stones) {
//         ans = INT_MAX;
//         f(0,0,stones);
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> dp;
//     int f(int i,int sum,vector<int> &nums){
//         if(i == nums.size()){
//             return abs(sum);
//         }
//         if(dp[i][sum+3000] != -1)return dp[i][sum + 3000];
//         int a = f(i+1,sum + nums[i],nums);
//         int b = f(i+1,sum-nums[i],nums);
//         return dp[i][sum + 3000] = min(a,b);
//     }
// public:
//     int lastStoneWeightII(vector<int>& stones) {
//         dp.assign(stones.size(),vector<int> (6001,-1));
//         return f(0,0,stones);
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> dp;

//     bool f(int i, int sum, vector<int>& stones) {
//         if (sum == 0)
//             return true;

//         if (i == stones.size() || sum < 0)
//             return false;

//         if (dp[i][sum] != -1)
//             return dp[i][sum];

//         bool take = f(i + 1, sum - stones[i], stones);
//         bool skip = f(i + 1, sum, stones);

//         return dp[i][sum] = take || skip;
//     }

//     int lastStoneWeightII(vector<int>& stones) {
//         int total = 0;

//         for (int x : stones)
//             total += x;

//         int target = total / 2;

//         dp.assign(stones.size(), vector<int>(target + 1, -1));

//         for (int x = target; x >= 0; x--) {
//             if (f(0, x, stones)) {
//                 return total - 2 * x;
//             }
//         }

//         return total;
//     }
// };

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
       bitset<6001> dp;
       int a = 3000;
       dp[a] = 1;
       for(int i : stones){
          dp = (dp << i) | (dp >> i);
       }
       for(int i=0; i<=3000; i++){
           if(dp[a + i] || dp[a-i]){
            return i;
           }
       }
       return -1;
    }
};