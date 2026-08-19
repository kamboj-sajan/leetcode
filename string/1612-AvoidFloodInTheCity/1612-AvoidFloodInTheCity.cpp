// Last updated: 19/08/2026, 15:47:16
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);  
        unordered_map<int, int> full;  
        set<int> dry;  

        for (int i = 0; i < n; i++) {
            if (rains[i] > 0) {
                int lake = rains[i];
                ans[i] = -1; 

                if (full.find(lake) != full.end()) {
                    
                    auto it = dry.lower_bound(full[lake]);
                    if (it == dry.end()) {
                        return {}; 
                    }
                    ans[*it] = lake; 
                    dry.erase(it);
                }

                full[lake] = i; 
            } else {
                dry.insert(i); 
            }
        }

        return ans;
    }
};
