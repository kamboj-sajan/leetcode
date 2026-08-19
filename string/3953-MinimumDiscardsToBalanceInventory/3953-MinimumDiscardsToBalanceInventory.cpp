// Last updated: 19/08/2026, 15:23:13
class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n = arrivals.size();
        unordered_map<int,int> freq;
        vector<bool> kept(n, false);
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (i >= w && kept[i - w]) {
                freq[arrivals[i - w]]--;
            }
            int type = arrivals[i];
            if (freq[type] == m) {
                ans++;
            } else {
                freq[type]++;
                kept[i] = true;
            }
        }
        
        return ans;
    }
};