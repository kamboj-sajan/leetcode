// Last updated: 24/09/2026, 00:52:11
class Solution {
public:
    int mirrorDistance(int n) {
        string a = to_string(n);
        string c = "";
        for(int i=0; i<a.size(); ++i){
            c.push_back(a[a.size()-1-i]);
        }
        int b = stoi(c);
        return abs(n-b);
    }
};