// Last updated: 19/08/2026, 15:16:26
class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double> ans;
        sort(sides.begin(), sides.end());
        int a = sides[0], b = sides[1], c = sides[2];
        if (a + b <= c) return ans;
        double A = acos((b*b + c*c - a*a) / (2.0 * b * c)) * 180.0 / M_PI;
        double B = acos((a*a + c*c - b*b) / (2.0 * a * c)) * 180.0 / M_PI;
        double C = 180.0 - (A + B);
        ans = {A, B, C};
        sort(ans.begin(), ans.end());
        return ans;
    }
};