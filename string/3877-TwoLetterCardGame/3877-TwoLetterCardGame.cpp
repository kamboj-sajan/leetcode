// Last updated: 19/08/2026, 15:24:20

class Solution {
public:
    int score(vector<string>& cards, char x) {
        unordered_map<char,int> lt, rt;
        int xx = 0;
        for (auto &s : cards) {
            if (s[0] == x && s[1] == x) xx++;
            else if (s[0] == x) lt[s[1]]++;
            else if (s[1] == x) rt[s[0]]++;
        }
        int nL = 0, maxL = 0;
        for (auto &p : lt) { nL += p.second; maxL = max(maxL, p.second); }
        int nR = 0, maxR = 0;
        for (auto &p : rt) { nR += p.second; maxR = max(maxR, p.second); }
        int Lmax = min(nL/2, nL - maxL);
        int Rmax = min(nR/2, nR - maxR);
        int S = nL + nR;
        int Kmin = 0;
        int Kmax = Lmax + Rmax;
        vector<int> cand = {Kmin, Kmax, (S - xx) / 2, (S - xx + 1) / 2};
        unordered_set<int> seen;
        long long best = 0;
        for (int k : cand) {
            if (k < Kmin) k = Kmin;
            if (k > Kmax) k = Kmax;
            if (seen.count(k)) continue;
            seen.insert(k);
            int leftover = S - 2 * k;
            if (leftover < 0) leftover = 0;
            long long val = (long long)k + (long long)min(xx, leftover);
            if (val > best) best = val;
        }
        
        int center = (S - xx) / 2;
        for (int d = -2; d <= 2; ++d) {
            int k = center + d;
            if (k < Kmin) k = Kmin;
            if (k > Kmax) k = Kmax;
            if (seen.count(k)) continue;
            seen.insert(k);
            int leftover = S - 2 * k;
            if (leftover < 0) leftover = 0;
            long long val = (long long)k + (long long)min(xx, leftover);
            if (val > best) best = val;
        }
        return (int)best;
    }
};
