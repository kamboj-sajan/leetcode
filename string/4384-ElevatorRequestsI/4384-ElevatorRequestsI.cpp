// Last updated: 19/08/2026, 15:14:54
class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int t = 0;
        t += requests[0];
        for(int i=1; i<requests.size(); i++){
            int a = (abs(requests[i] - requests[i-1]));
            t += a;
        }
        return t;
    }
};