// Last updated: 19/08/2026, 15:33:58
/*
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totsum = 0;
        for(int i=0; i<n; i++)totsum += nums[i];
        int k = totsum;
         vector<char> prev(totsum + 1, false);
        prev[0] = 1;
       if (nums[0] <= k)
            prev[nums[0]] = 1;
        for(int i=1; i<n; i++){
             vector<char> cur(totsum + 1, false);
            cur[0] = 1;
            for(int target = 1; target <= k; target++){
                bool notTake = prev[target];
                bool take = false;
                if (target >= nums[i])take = prev[target-nums[i]];
                cur[target] = take | notTake;
            }
             prev = cur;
        }
        int mini = 1e9;
        for(int i=0; i<=k/2; i++){
            if(prev[i] == true)
            mini = min(mini,abs((totsum - i) - i ));
        }
        return mini;
    }
};
*/

/*
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
       int totsum = 0;
       for(int i=0; i<n; i++)totsum += nums[i];
       int k = totsum;
       vector<vector<char>> dp(n,vector<char>(k+1,0));
       for(int i=0; i<n; i++)dp[i][0] = 1;
       if(nums[0] <= k)dp[0][nums[0]] = 1;
       for(int i=1; i<n; i++){
        for(int target=1; target<=k; target++){
            bool notTake = dp[i-1][target];
            bool take = false;
            if(nums[i] <= target)take = dp[i-1][target-nums[i]];
            dp[i][target] = take | notTake;
        }
       }
       int mini = 1e9;
       for(int i=0; i<totsum; i++){
        if(dp[n-1][i] == true){
            int S1 = i;
            int S2 = totsum - i;
            mini = min(mini,abs(S2-S1));
        }
       }
       return mini;
    }
};
*/


class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        // Function to get all subset sums grouped by subset size
        auto getSubsetSums = [](vector<int>& arr) {
            int m = arr.size();
            vector<vector<int>> subsets(m + 1); // subsets[i] contains all sums of subsets of size i
            for (int mask = 0; mask < (1 << m); ++mask) {
                int sum = 0;
                int bits = 0;
                for (int i = 0; i < m; ++i) {
                    if (mask & (1 << i)) {
                        sum += arr[i];
                        bits++;
                    }
                }
                subsets[bits].push_back(sum);
            }
            return subsets;
        };

        // Get subset sums for left and right halves
        vector<vector<int>> left_sums = getSubsetSums(left);
        vector<vector<int>> right_sums = getSubsetSums(right);

        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total / 2;
        int res = INT_MAX;

        // Try all combinations of k elements from left and (n-k) from right
        for (int k = 0; k <= n; ++k) {
            auto& left_vec = left_sums[k];
            auto& right_vec = right_sums[n - k];
            sort(right_vec.begin(), right_vec.end());

            for (int lsum : left_vec) {
                int rem = target - lsum;
                auto it = lower_bound(right_vec.begin(), right_vec.end(), rem);

                // Try the current or next greater right subset sum
                if (it != right_vec.end()) {
                    int sum = lsum + *it;
                    res = min(res, abs(total - 2 * sum));
                }
                // Try the previous (just smaller) right subset sum
                if (it != right_vec.begin()) {
                    --it;
                    int sum = lsum + *it;
                    res = min(res, abs(total - 2 * sum));
                }
            }
        }

        return res;
    }
};
