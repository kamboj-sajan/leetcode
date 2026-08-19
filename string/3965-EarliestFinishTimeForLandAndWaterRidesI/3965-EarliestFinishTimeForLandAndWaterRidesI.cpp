// Last updated: 19/08/2026, 15:22:53
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
         int n = landStartTime.size();
        int m = waterStartTime.size();
        
        int ans = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                // Case 1: Land -> Water
                int finishLand = landStartTime[i] + landDuration[i];
                int startWater = max(finishLand, waterStartTime[j]);
                int total1 = startWater + waterDuration[j];
                
                // Case 2: Water -> Land
                int finishWater = waterStartTime[j] + waterDuration[j];
                int startLand = max(finishWater, landStartTime[i]);
                int total2 = startLand + landDuration[i];
                
                ans = min(ans, min(total1, total2));
            }
        }
        
        return ans;
    }
};