// Last updated: 19/08/2026, 15:21:09
class Solution {
private:
    bool isPartitionPossible(int d, int n, const vector<vector<int>>& points) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long dist = static_cast<long long>(abs(points[i][0] - points[j][0])) +
                                 static_cast<long long>(abs(points[i][1] - points[j][1]));
                if (dist < d) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> color(n, 0);

        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                queue<int> q;
                q.push(i);
                color[i] = 1;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v : adj[u]) {
                        if (color[v] == 0) {
                            color[v] = -color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
public:
    int maxPartitionFactor(vector<vector<int>>& points) {
     int n = points.size();
        
        if (n <= 2) {
            return 0;
        }

        int low = 0;
        int high = 400000001;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isPartitionPossible(mid, n, points)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};