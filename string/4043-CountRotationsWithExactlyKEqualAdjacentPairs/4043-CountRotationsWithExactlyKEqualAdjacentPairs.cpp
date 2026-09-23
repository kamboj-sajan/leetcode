// Last updated: 24/09/2026, 00:48:21
class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        string temp = s;
        int ans = 0;
        for(int i=0; i<n; i++){
            string str = temp.substr(i) + temp.substr(0,i);
            int cnt =0;
            for(int i=0; i<n-1; i++){
                if(str[i] == str[i+1])cnt++;
            }
            if(cnt == k)ans++;
        }
        return ans;
    }
};