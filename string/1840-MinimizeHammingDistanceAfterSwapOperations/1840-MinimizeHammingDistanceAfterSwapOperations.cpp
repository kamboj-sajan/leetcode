// Last updated: 19/08/2026, 15:37:04
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);

        // Initialize parent
        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Step 1: Build components
        for (auto &p : allowedSwaps)
            unite(p[0], p[1]);

        // Step 2: Group indices
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++)
            groups[find(i)].push_back(i);

        int hamming = 0;

        // Step 3: Compare within each group
        for (auto &g : groups) {
            unordered_map<int, int> freq;

            // Count source values
            for (int idx : g.second)
                freq[source[idx]]++;

            // Match target values
            for (int idx : g.second) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    hamming++;
                }
            }
        }

        return hamming;
    }
};