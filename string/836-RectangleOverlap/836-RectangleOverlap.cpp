// Last updated: 25/09/2026, 01:19:40
// class Solution {
// public:
//     bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
//         return rec1[0] < rec2[2] &&
//                rec2[0] < rec1[2] &&
//                rec1[1] < rec2[3] &&
//                rec2[1] < rec1[3];
//     }
// };

class Solution {
public:
    bool inside(int a, int x, int b){
        return ((a <= x) && (x < b));
    }
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool x = inside(rec1[0], rec2[0], rec1[2]) || inside(rec2[0], rec1[0], rec2[2]);
        bool y = inside(rec1[1], rec2[1], rec1[3]) || inside(rec2[1], rec1[1], rec2[3]);
        cout << x << ' ' << y;
        return (x && y);
    }
};