// Last updated: 19/08/2026, 15:33:54
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        
        // sort by start time
        sort(events.begin(), events.end());
        
        // suffixMax[i] = max value from i to n-1
        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; --i) {
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            // take only this event
            ans = max(ans, events[i][2]);
            
            // binary search for next non-overlapping event
            int lo = i + 1, hi = n - 1;
            int idx = -1;
            
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (events[mid][0] >= events[i][1] + 1) {
                    idx = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            
            if (idx != -1) {
                ans = max(ans, events[i][2] + suffixMax[idx]);
            }
        }
        
        return ans;
    }
};
