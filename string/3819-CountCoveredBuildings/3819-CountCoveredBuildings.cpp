// Last updated: 19/08/2026, 15:25:10
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int,int>> row; // row[x] = {minY, maxY}
        unordered_map<int, pair<int,int>> col; // col[y] = {minX, maxX}

        const int INF = 1e9;

        // First pass: compute min/max in each row and column
        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            if (!row.count(x)) row[x] = {INF, -INF};
            if (!col.count(y)) col[y] = {INF, -INF};

            row[x].first  = min(row[x].first, y);
            row[x].second = max(row[x].second, y);

            col[y].first  = min(col[y].first, x);
            col[y].second = max(col[y].second, x);
        }

        int covered = 0;

        // Second pass: check if building is covered
        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            auto [rmin, rmax] = row[x];
            auto [cmin, cmax] = col[y];

            if (rmin < y && y < rmax && cmin < x && x < cmax)
                covered++;
        }

        return covered;
    }
};