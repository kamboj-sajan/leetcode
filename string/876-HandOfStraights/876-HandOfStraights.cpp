// Last updated: 19/08/2026, 15:56:13
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0)return false;
        map<int,int> mpp;
        for(int i=0; i<n; ++i){
            mpp[hand[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto &a : mpp){
            pq.push({a.first,a.second});
        }
        while(!pq.empty()){
            int temp = groupSize;
            vector<pair<int,int>> tpp;
            int prevval = -1;
            while(temp > 0){
                if(pq.empty()) return false;
                auto [val,f] = pq.top();
                if(val == prevval + 1 || prevval == -1){
                    prevval = val;
                }
                else{
                    return false;
                }
                pq.pop();
                if(--f > 0)tpp.push_back({val,f});
                temp--;
            }
            for(auto b : tpp)pq.push(b);
        }
        return true;
    }
};