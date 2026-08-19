// Last updated: 19/08/2026, 15:59:24
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;

        for (int k = n - 1; k >= 2; k--) {   // largest side
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    count += (j - i); // all pairs (i..j-1) with j are valid
                    j--;
                } else {
                    i++;
                }
            }
        }

        return count;
    }
};