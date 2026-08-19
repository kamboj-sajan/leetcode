// Last updated: 19/08/2026, 15:18:35
class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
       int ans = 0;
        int b = 0;  
        for (int i = 16; i >= 0; --i) {
            int temp = b | (1 << i);
            bool a = true;
            for (auto &r : grid) {
                bool c = false;
                for (int x : r) {
                    if ((x & temp) == 0) {
                        c = true;
                        break;
                    }
                }
                if (!c) {
                    a = false;
                    break;
                }
            }
            if (a) {
                b |= (1 << i);   
            } else {
                ans |= (1 << i); 
            }
        }
        return ans;
    }
};