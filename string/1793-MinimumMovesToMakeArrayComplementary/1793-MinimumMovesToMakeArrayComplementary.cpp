// Last updated: 19/08/2026, 15:37:57
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
    
    // Difference array
    vector<int> diff(2 * limit + 2, 0);

    for (int i = 0; i < n / 2; i++) {
        int a = nums[i];
        int b = nums[n - 1 - i];

        int low = min(a, b) + 1;
        int high = max(a, b) + limit;
        int sum = a + b;

        // Assume 2 moves for all sums
        diff[2] += 2;
        diff[2 * limit + 1] -= 2;

        // Reduce to 1 move range
        diff[low] -= 1;
        diff[high + 1] += 1;

        // Reduce to 0 move for exact sum
        diff[sum] -= 1;
        diff[sum + 1] += 1;
    }

    int res = INT_MAX;
    int curr = 0;

    // Prefix sum to compute minimum moves
    for (int s = 2; s <= 2 * limit; s++) {
        curr += diff[s];
        res = min(res, curr);
    }

    return res;
    }
};