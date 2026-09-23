// Last updated: 24/09/2026, 00:48:39
class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        vector<int> vec;
        for(int i=0; i<n-1; i++){
            if(position[i+1] - position[i] > distance)vec.push_back(speed[i]);
        }
        vec.push_back(speed[n-1]);
        int ans = 1;
        int temp = vec[vec.size()-1];
        for(int i=(int)vec.size()-2; i>=0; i--){
            if(vec[i] <= temp){
                ans++;
                temp = vec[i];
            }
        }
        return ans;
    }
};