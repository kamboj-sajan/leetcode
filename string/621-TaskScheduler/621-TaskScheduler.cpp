// Last updated: 19/08/2026, 15:59:08
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int k = tasks.size();
        unordered_map<char,int> mpp;
        for(int i=0; i<k; i++){
            mpp[tasks[i]]++;
        }
        priority_queue<int> pq;
        for(auto &a : mpp){
            pq.push(a.second);
        }
        int t = 0;
        while(!pq.empty()){
            vector<int> temp;
            int cycle = n+1;
            while(cycle > 0 && !pq.empty()){
                int f = pq.top();
                pq.pop();
                if(--f > 0)temp.push_back(f);
                t++;
                cycle--;
            }
            for(int f : temp)pq.push(f);
            if(!pq.empty())t += cycle;
        }
        return t;
    }
};