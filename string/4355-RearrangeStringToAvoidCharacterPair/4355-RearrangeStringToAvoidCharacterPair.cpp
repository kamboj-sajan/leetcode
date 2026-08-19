// Last updated: 19/08/2026, 15:15:07
class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        unordered_map<char,int> mpp;
        string ans = "";
        for(auto c : s){
            mpp[c]++;
        }
        while(mpp[y]!=0){
            ans += y;
            mpp[y]--;
        }
        for(auto it : mpp){
            for(int i=0; i<it.second; i++){
                ans += it.first;
            }
        }
        return ans;
    }
};