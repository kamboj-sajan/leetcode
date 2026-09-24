// Last updated: 25/09/2026, 01:04:18
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