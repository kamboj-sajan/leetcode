// Last updated: 19/08/2026, 15:46:45
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailing(n);

        // Count trailing zeros in each row
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) cnt++;
                else break;
            }
            trailing[i] = cnt;
        }

        int swaps = 0;

        // Place correct row at each position
        for (int i = 0; i < n; i++) {
            int need = n - 1 - i;
            int j = i;

            // find suitable row
            while (j < n && trailing[j] < need)
                j++;

            if (j == n) return -1; // impossible

            // bring row j to i using adjacent swaps
            while (j > i) {
                swap(trailing[j], trailing[j - 1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};