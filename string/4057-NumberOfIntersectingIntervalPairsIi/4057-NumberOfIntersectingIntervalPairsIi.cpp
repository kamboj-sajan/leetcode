// Last updated: 24/09/2026, 00:48:25
class Solution {
public:
    using ll = long long;
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        ll n = intervals.size();
        ll tp = n*(n-1)/2;
        vector<int> vec(n);
        for(int i=0; i<n; i++){
            vec[i] = intervals[i][0];
        }
        sort(vec.begin(),vec.end());
        ll cnt = 0;
        for(int i=0; i<n; i++){
            int lt = intervals[i][1];
            auto p = upper_bound(vec.begin(),vec.end(),lt);
            cnt += distance(p,vec.end());
        }
        return tp - cnt;
    }
};