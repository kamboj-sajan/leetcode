// Last updated: 19/08/2026, 15:21:32
class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0; i<friends.size(); i++){
            for(int j=0; j<order.size(); j++){
                if(friends[i] == order[j]){
                    pq.push({j,friends[i]});
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};