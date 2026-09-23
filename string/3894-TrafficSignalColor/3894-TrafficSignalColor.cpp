// Last updated: 24/09/2026, 00:49:58
class Solution {
public:
    string trafficSignal(int t) {
        if(t == 0)return "Green";
        else if(t == 30)return "Orange";
        else if(t > 30 && t <=90)return "Red";
        return "Invalid";
    }
};