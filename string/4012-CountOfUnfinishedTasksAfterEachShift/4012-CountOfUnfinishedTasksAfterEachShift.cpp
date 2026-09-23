// Last updated: 24/09/2026, 00:51:27
class Solution {
    
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
         using ll = long long;
        int n = tasks.size();
        ll sum = 0;
        vector<ll> pre(n);
        for(int i=0; i<n; i++){
            sum += tasks[i];
            pre[i] = sum;
        }
        ll temp = 0;
        vector<int> ans;
        for(int i=0; i<shifts.size(); i++){
            if(temp + shifts[i] >= sum){
                ans.push_back(0);
                temp = 0;
            }else{
                temp += shifts[i];
                int a = upper_bound(pre.begin(),pre.end(),temp) - pre.begin();
                ans.push_back(n-a);
            }
        }
        return ans;
    }
};