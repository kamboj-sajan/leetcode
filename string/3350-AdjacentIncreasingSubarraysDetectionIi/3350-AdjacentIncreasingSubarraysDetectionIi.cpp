// Last updated: 25/09/2026, 01:00:02
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
       int n=nums.size();
        int i=0, j=1;
        int ans = 0;
        int prev = 0;
        while (j<n){
            if (nums[j] <= nums[j-1]){
                ans = max ({ans, (j-i)/2, min (prev, j-i)});
                prev = j-i;
                i=j;
            }
            j++;
        }
        ans = max ({ans, (j-i)/2, min (prev, j-i)});
        return ans;
    }
};