// Last updated: 19/08/2026, 15:57:23
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
       for(int i=0; i<jewels.size(); ++i){
        for(int j=0; j<stones.size(); ++j){
            if(jewels[i] == stones[j]){
                ans++;
            }
        }
       } 
       return ans;
    }
};