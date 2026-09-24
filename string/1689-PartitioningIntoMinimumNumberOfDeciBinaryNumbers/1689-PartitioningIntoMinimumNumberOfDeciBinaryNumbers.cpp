// Last updated: 25/09/2026, 01:10:35
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