// Last updated: 19/08/2026, 15:30:43
class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        
        // Step 1: validate diagonal
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
        }
        
        // Step 2: validate symmetry
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] != lcp[j][i]) return "";
            }
        }
        
        // Step 3: validate recurrence
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == n-1 || j == n-1) {
                    if (lcp[i][j] > 1) return "";
                } else {
                    if (lcp[i][j] > 0) {
                        if (lcp[i][j] != 1 + lcp[i+1][j+1]) return "";
                    }
                }
            }
        }
        
        // DSU
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        
        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) parent[a] = b;
        };
        
        // Step 4: union positions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] > 0) {
                    unite(i, j);
                }
            }
        }
        
        // Step 5: assign characters
        string res(n, '?');
        unordered_map<int, char> mp;
        char ch = 'a';
        
        for (int i = 0; i < n; i++) {
            int root = find(i);
            if (!mp.count(root)) {
                if (ch > 'z') return "";
                mp[root] = ch++;
            }
            res[i] = mp[root];
        }
        
        // Step 6: verify by recomputing LCP
        vector<vector<int>> check(n, vector<int>(n, 0));
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (res[i] == res[j]) {
                    if (i == n-1 || j == n-1) check[i][j] = 1;
                    else check[i][j] = 1 + check[i+1][j+1];
                }
            }
        }
        
        if (check != lcp) return "";
        
        return res;
    }
};