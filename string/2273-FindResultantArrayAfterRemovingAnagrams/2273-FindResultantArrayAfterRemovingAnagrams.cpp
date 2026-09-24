// Last updated: 25/09/2026, 01:14:49
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string prev = "";
        for(auto &w : words){
            string st = w;
            sort(st.begin(),st.end());
            if(st != prev){
                ans.push_back(w);
                prev = st;
            }
        }
        return ans;
    }
};