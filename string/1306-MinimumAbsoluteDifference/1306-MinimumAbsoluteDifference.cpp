// Last updated: 19/08/2026, 15:51:12
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
         sort(arr.begin(), arr.end());

        int mn = INT_MAX;
        for (int i = 1; i < (int)arr.size(); i++)
            mn = min(mn, arr[i] - arr[i - 1]);

        vector<vector<int>> res;
        for (int i = 1; i < (int)arr.size(); i++) {
            if (arr[i] - arr[i - 1] == mn)
                res.push_back({arr[i - 1], arr[i]});
        }
        return res;
    }
};