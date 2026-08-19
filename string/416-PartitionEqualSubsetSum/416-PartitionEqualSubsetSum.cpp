// Last updated: 19/08/2026, 16:01:49
class Solution {
private:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        vector<int> prev(k+1,0), cur(k+1,0);
        prev[0] = cur[0] = true;
       if (arr[0] <= k)
            prev[arr[0]] = true;
        for(int i=1; i<n; i++){
            for(int target = 1; target <= k; target++){
                bool notTake = prev[target];
                bool take = false;  
                if(arr[i] <= target)take = prev[target-arr[i]];
                cur[target] = take | notTake;
            }
            prev = cur;
        }
        return prev[k];
    }
public:
    bool canPartition(vector<int>& nums) {
        int totsum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)totsum += nums[i];
        if(totsum % 2)return false;
        int k = totsum/2;
        return checkSubsequenceSum(n,nums,k);
    }
};