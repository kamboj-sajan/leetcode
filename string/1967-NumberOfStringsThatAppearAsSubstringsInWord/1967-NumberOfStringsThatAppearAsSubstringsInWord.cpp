// Last updated: 25/09/2026, 01:08:11
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