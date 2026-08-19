// Last updated: 19/08/2026, 15:31:00
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int mini = INT_MAX;
        int n = words.size();
        for(int i = 0; i<n; ++i){
            if(words[i] == target){
                int diff = abs(i - startIndex);
                int steps = min(diff, n - diff);
                mini = min(mini, steps);
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};