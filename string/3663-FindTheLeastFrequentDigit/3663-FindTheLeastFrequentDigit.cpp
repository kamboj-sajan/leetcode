// Last updated: 25/09/2026, 00:55:41
class Solution {
public:
    int getLeastFrequentDigit(int n) {
       unordered_map<int,int> mpp;
        string str = to_string(n);
        int s = str.size();
        for(int i=0; i<s; i++){
            mpp[str[i] - '0']++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto &a : mpp){
            pq.push({a.second,a.first});
        }
        return pq.top().second;
    }
};