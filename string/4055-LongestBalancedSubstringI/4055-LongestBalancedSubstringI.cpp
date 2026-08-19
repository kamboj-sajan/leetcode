// Last updated: 19/08/2026, 15:20:49
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxi = 0;
        for(int i=0; i<s.size(); ++i){
            unordered_map<char,int> mpp;
            for(int j=i; j<n; ++j){
                mpp[s[j]]++;
                int fr = mpp.begin()->second;
                bool balanc = true;
                for(auto &p : mpp){
                    if(p.second != fr){
                        balanc = false;
                        break;
                    }
                }
                if(balanc){
                    maxi = max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};