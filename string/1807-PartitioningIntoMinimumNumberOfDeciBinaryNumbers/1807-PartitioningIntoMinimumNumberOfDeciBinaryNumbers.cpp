// Last updated: 19/08/2026, 15:37:36
class Solution {
public:
    int minPartitions(string n) {
        char maxi = '0';
        for(int i=0; i<n.size(); ++i){
            if(n[i] > maxi)maxi = n[i];
        }
        return maxi-'0';
    }
};