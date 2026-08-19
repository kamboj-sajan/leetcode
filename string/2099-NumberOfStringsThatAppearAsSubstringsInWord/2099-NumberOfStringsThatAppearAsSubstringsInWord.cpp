// Last updated: 19/08/2026, 15:34:36
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        int cnt = 0;
        for(string &s : patterns){
            if(word.find(s) != string::npos)cnt++;
        }
        return cnt;
    }
};