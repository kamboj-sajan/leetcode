// Last updated: 19/08/2026, 15:17:54
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int maxi = INT_MIN;
        sort(towers.begin(),towers.end());
        int n = towers.size();
        int xi = -1;
        int ji = -1;
        for(int i=0; i<n; ++i){
            if((abs(towers[i][0] - center[0]) + abs(towers[i][1] - center[1])) <= radius){
                if(towers[i][2] > maxi){
                    maxi = towers[i][2];
                    xi = towers[i][0];
                    ji = towers[i][1];
                }
            }
        }
        vector<int> ans;
        ans.push_back(xi);
        ans.push_back(ji);
        return ans;
    }
};