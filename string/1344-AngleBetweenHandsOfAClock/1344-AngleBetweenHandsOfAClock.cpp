// Last updated: 25/09/2026, 01:14:04
// class Solution {
// public:
//     double angleClock(int hour, int minutes) {
//         double hd = minutes*0.5 + 30.0*hour;
//         double md = minutes*6.0;
//         double dif = abs(md - hd);
//         return min(dif,360.0-dif);
//     }
// };

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans;
        double h=30*hour+0.5*minutes;
        double m=6*minutes;
        ans=abs(h-m);
        return min(ans,360-ans);
    }
};