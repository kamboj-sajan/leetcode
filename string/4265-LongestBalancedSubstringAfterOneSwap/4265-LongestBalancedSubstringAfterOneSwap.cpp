// Last updated: 19/08/2026, 15:16:29
class Solution {
public:
    int longestBalanced(string s) {
       int n = s.size();
        unordered_map<int, vector<int>> mpp;
        mpp[0].push_back(-1);
        int sum = 0;
        int ans = 0;
        int cnt0 = 0;
        int cnt1 = 0;
        for (char c : s) {
            if (c == '0') cnt0++;
            else cnt1++;
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') sum += 1;
            else sum -= 1;
            if (mpp.count(sum)) {
                ans = max(ans, i - mpp[sum][0]);
            }
            if (mpp.count(sum - 2)) {
                int b = i - 2 * cnt0; 
                auto it = lower_bound(mpp[sum - 2].begin(), mpp[sum - 2].end(), b);
                if (it != mpp[sum - 2].end()) {
                    ans = max(ans, i - *it);
                }
            }
            if (mpp.count(sum + 2)) {
                int b = i - 2 * cnt1; 
                auto it = lower_bound(mpp[sum + 2].begin(), mpp[sum + 2].end(), b);
                if (it != mpp[sum + 2].end()) {
                    ans = max(ans, i - *it);
                }
            }
            mpp[sum].push_back(i);
        }
        
        return ans;
    }
};