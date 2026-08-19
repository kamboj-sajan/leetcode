// Last updated: 19/08/2026, 15:16:20
class EventManager {
public:
    priority_queue<pair<int,int>> pq;
    unordered_map<int,int> mpp;
    EventManager(vector<vector<int>>& events) {
        for(auto &i : events){
            int id = i[0];
            int p = i[1];
            mpp[id] = p;
            pq.push({p,-id});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mpp[eventId] = newPriority;
        pq.push({newPriority,-eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto a = pq.top();
            int id = -a.second;
            if(mpp.count(id) && mpp[id] == a.first){
                pq.pop();
                mpp.erase(id);
                return id;
            }
            pq.pop();
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */