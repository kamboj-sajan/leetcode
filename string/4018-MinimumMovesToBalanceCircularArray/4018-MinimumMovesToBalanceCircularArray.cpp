// Last updated: 19/08/2026, 15:21:26
class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();
        long long sum = 0;
        int tl = -1;
        for(int i=0; i<n; ++i){
            sum += balance[i];
            if(balance[i] < 0)tl = i;
        }
        if(sum < 0)return -1;
        if(tl == -1)return 0;
        long long blc = -balance[tl];
        long long tmove = 0;
        int l = (tl - 1 + n)%n;
        int r = (tl+1)%n;
        int dist = 1;
        while(blc > 0){
            if(balance[l] > 0){
                long long tk = min((long long)balance[l],blc);
                blc -= tk;
                tmove += tk * dist;
                balance[l] -= tk;
            }
            if(blc == 0)break;
            if(balance[r] > 0){
                long long tk = min((long long)balance[r],blc);
                blc -= tk;
                tmove += tk * dist;
                balance[r] -= tk;
            }
            l = (l-1+n)%n;
            r = (r+1)%n;
            dist++;
        }
        return tmove;
    }
};