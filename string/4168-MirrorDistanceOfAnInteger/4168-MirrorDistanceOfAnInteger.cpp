// Last updated: 19/08/2026, 15:18:25
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