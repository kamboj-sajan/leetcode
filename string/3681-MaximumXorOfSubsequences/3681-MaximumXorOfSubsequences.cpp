// Last updated: 25/09/2026, 00:55:45
class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        vector<int> b(31,0);
        for(int a : nums){
            int x = a;
            for(int i=30; i>=0; --i){
                if((x >> i) & 1){
                    if(!b[i]){
                        b[i] = x;
                        break;
                    }
                    x ^= b[i];
                }
            }
        }
        int maxa = 0;
        for(int i=30; i>=0; --i){
            if((maxa ^ b[i]) > maxa){
                maxa ^= b[i];
            }
        }
        return maxa;
    }
};