// Last updated: 19/08/2026, 15:51:58
// class Solution {
// public:
//     vector<int> arrayRankTransform(vector<int>& arr) {
//         vector<int> s = arr;
//         sort(s.begin(), s.end());
//         s.erase(unique(s.begin(), s.end()), s.end());
//         for (int i = 0; i < arr.size(); i++) {
//             arr[i] = lower_bound(s.begin(), s.end(), arr[i]) - s.begin() + 1;
//         }
//         return arr;
//     }
// };

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};
        vector<int> res(n);
        vector<pair<int,int>> temp(n);
        for (int i = 0; i < n; i++) temp[i] = {arr[i],i};
        sort(temp.begin(),temp.end(),[](pair<int,int> &a , pair<int,int> &b) {
            return a.first < b.first;
        });
        res[temp[0].second] = 1;
        for (int i = 1; i < n; i++) {
            if (temp[i].first == temp[i - 1].first) res[temp[i].second] = res[temp[i - 1].second];
            else res[temp[i].second] = res[temp[i - 1].second] + 1;
        }
        return res;
    }
};