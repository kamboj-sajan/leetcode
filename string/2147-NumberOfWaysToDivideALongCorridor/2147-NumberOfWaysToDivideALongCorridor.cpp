// Last updated: 25/09/2026, 01:06:43
class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        long long ans = 1;
        int seats = 0;
        int plants = 0;
        bool countingPlants = false;
        for(char c : corridor) {
            if(c == 'S') {
                seats++;
                if(seats % 2 == 0) {
                    countingPlants = true;
                } else {
                    if(countingPlants) {
                        ans = (ans * (plants + 1)) % MOD;
                        plants = 0;
                        countingPlants = false;
                    }
                }
            } else {
                if(countingPlants) plants++;
            }
        }
        if(seats == 0 || seats % 2 != 0) return 0;
        return ans;
    }
};
