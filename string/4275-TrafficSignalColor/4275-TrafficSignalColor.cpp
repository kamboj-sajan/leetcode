// Last updated: 19/08/2026, 15:16:05
class Solution {
public:
    string trafficSignal(int t) {
        if(t == 0)return "Green";
        else if(t == 30)return "Orange";
        else if(t > 30 && t <=90)return "Red";
        return "Invalid";
    }
};