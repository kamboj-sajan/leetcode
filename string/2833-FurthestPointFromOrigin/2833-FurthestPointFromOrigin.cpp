// Last updated: 25/09/2026, 01:02:59
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0;
        int r = 0;
        int bl = 0;
        for(int i=0;i<moves.size(); ++i){
            if(moves[i] == 'L')l++;
            else if(moves[i] == 'R')r++;
            else bl++;
        }
        return abs(r-l) + bl;
    }
};