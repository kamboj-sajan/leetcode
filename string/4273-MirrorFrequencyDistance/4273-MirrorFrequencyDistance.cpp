// Last updated: 19/08/2026, 15:16:09
class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> fr(36,0);
        for(char p : s){
            if(isdigit(p)){
                fr[p - '0' + 26]++;
            }else{
                fr[p - 'a']++;
            }
        }
        int ans = 0;
        for(int i=0; i<13; ++i){
            ans += abs(fr[i] - fr[25-i]);
        }
        for(int i=0; i<5; ++i){
            ans += abs(fr[26 + i] - fr[26 + 9 -i]);
        }
        return ans;
    }
};