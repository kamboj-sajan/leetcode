// Last updated: 19/08/2026, 16:00:53
class Solution {
     public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<int> prev(target+1,0), cur(target+1,0);
        if(arr[0] == 0)prev[0] = 2;
       else prev[0] = 1;
        if(arr[0] != 0 && arr[0] <= target)prev[arr[0]] = 1;
        for(int i=1; i<n; i++){
            for(int s=0; s<=target; s++){
                int notTake = prev[s];
                int take = 0;
                if(arr[i] <= s)take = prev[s-arr[i]];
                cur[s] = take + notTake;
            }
            prev = cur;
        }
        return prev[target];
};
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int totsum = 0;
        for(auto it : arr)totsum += it;
        if(totsum - d < 0 || (totsum - d) % 2)return 0;
        return perfectSum(arr,(totsum-d)/2);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       return countPartitions(nums,target); 
    }
};