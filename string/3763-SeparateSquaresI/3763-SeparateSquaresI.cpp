// Last updated: 19/08/2026, 15:26:01
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long double totalArea = 0;
        for (auto &s : squares) {
            long double l = s[2];
            totalArea += l * l;
        }

        long double target = totalArea / 2.0;

        long double low = 0, high = 1e9;

        for (int iter = 0; iter < 80; iter++) { // enough for 1e-5 precision
            long double mid = (low + high) / 2.0;
            long double areaBelow = 0;

            for (auto &s : squares) {
                long double y = s[1];
                long double l = s[2];

                if (mid <= y) continue;
                else if (mid >= y + l) areaBelow += l * l;
                else areaBelow += (mid - y) * l;
            }

            if (areaBelow < target)
                low = mid;
            else
                high = mid;
        }

        return (double)low;
    }
};
