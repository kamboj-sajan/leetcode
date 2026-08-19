// Last updated: 19/08/2026, 15:21:22
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
      int n = s.size();
        vector<int> f(26, 0);
        for (char c : s) f[c - 'a']++;

        string ans = "";
        bool found = false;

        function<void(int, bool, string&)> dfs = [&](int ind, bool great, string &cur) {
            if (found) return;
            if (ind == n) {
                if (great) {
                    ans = cur;
                    found = true;
                }
                return;
            }

            for (int ch = 0; ch < 26; ++ch) {
                if (f[ch] == 0) continue;
                char c = 'a' + ch;
                if (!great && c < target[ind]) continue;

                f[ch]--;
                cur.push_back(c);

                if (great || c > target[ind]) {
                    string rest = "";
                    for (int k = 0; k < 26; ++k)
                        rest.append(f[k], 'a' + k);
                    ans = cur + rest;
                    found = true;
                    return;
                } else {
                    dfs(ind + 1, false, cur);
                }

                cur.pop_back();
                f[ch]++;
                if (found) return;
            }
        };

        string cur = "";
        dfs(0, false, cur);
        return ans;
    }
};