// Last updated: 19/08/2026, 15:15:14
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            int temp = i;
            for(int j=0; j<n/2; j++){
                int l = (j+i)%n;
                int r = (n-1-j + i)%n;
                int d = abs((s[l] - 'a')-(s[r] - 'a'));
                temp += min(d,26-d);
            }
            ans = min(ans,temp);
        }
        return ans;
    }
};