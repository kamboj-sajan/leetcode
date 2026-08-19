// Last updated: 19/08/2026, 15:23:23
class Solution {
public:
    vector<int> bestAns;
    int minDiff = INT_MAX;
    unordered_map<string, bool> memo;

   
    string encode(vector<int>& group) {
        vector<int> tmp = group;
        sort(tmp.begin(), tmp.end());
        string s;
        for(int x : tmp) s += to_string(x) + ",";
        return s;
    }

    void dfs(vector<int>& group, vector<int>& primes, int idx) {
        if(idx == primes.size()) {
            int mn = *min_element(group.begin(), group.end());
            int mx = *max_element(group.begin(), group.end());
            if(mx - mn < minDiff) {
                minDiff = mx - mn;
                bestAns = group;
            }
            return;
        }

        string key = to_string(idx) + "|" + encode(group);
        if(memo.count(key)) return;  
        memo[key] = true;

        for(int i = 0; i < group.size(); i++) {
            group[i] *= primes[idx];
            dfs(group, primes, idx + 1);
            group[i] /= primes[idx];
            if(group[i] == 1) break; 
        }
    }

    vector<int> minDifference(int n, int k) {
        if(k == 2) {
            int best_d = 1, best_diff = n-1;
            for(int d = 1; d*d <= n; d++){
                if(n % d == 0){
                    int other = n/d;
                    if(abs(other - d) < best_diff){
                        best_diff = abs(other - d);
                        best_d = d;
                    }
                }
            }
            return {best_d, n/best_d};
        }

        vector<int> primes;
        int temp = n;
        for(int i=2; i*i <= temp; i++){
            while(temp % i == 0){
                primes.push_back(i);
                temp /= i;
            }
        }
        if(temp > 1) primes.push_back(temp);

        vector<int> group(k,1);
        dfs(group, primes, 0);

        sort(bestAns.begin(), bestAns.end());
        return bestAns;
    }
};
