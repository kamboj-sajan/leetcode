// Last updated: 19/08/2026, 15:20:44
class Solution {
public:
    int longestBalanced(string s) {
        int max_len = 0;
        if (s.empty()) {
            return 0;
        }

        int max_run = 0;
        int current_run = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (i > 0 && s[i] == s[i - 1]) {
                current_run++;
            } else {
                current_run = 1;
            }
            max_run = max(max_run, current_run);
        }
        max_len = max(max_run, max_len);

        unordered_map<long long, int> seen_abc, seen_ab_c0, seen_ac_b0, seen_bc_a0;

        seen_abc[0] = -1;
        seen_ab_c0[0] = -1;
        seen_ac_b0[0] = -1;
        seen_bc_a0[0] = -1;
        
        long long n = s.length();
        long long mult1 = 2 * n + 1; 
        long long mult2 = n + 1;     

        int ca = 0, cb = 0, cc = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a') ca++;
            else if (s[i] == 'b') cb++;
            else cc++;
            
            long long key_abc = (long long)(ca - cb) * mult1 + (ca - cc);
            if (seen_abc.count(key_abc)) {
                max_len = max(max_len, i - seen_abc[key_abc]);
            } else {
                seen_abc[key_abc] = i;
            }

            long long key_ab_c0 = (long long)(ca - cb) * mult2 + cc;
            if (seen_ab_c0.count(key_ab_c0)) {
                max_len = max(max_len, i - seen_ab_c0[key_ab_c0]);
            } else {
                seen_ab_c0[key_ab_c0] = i;
            }
            
            long long key_ac_b0 = (long long)(ca - cc) * mult2 + cb;
            if (seen_ac_b0.count(key_ac_b0)) {
                max_len = max(max_len, i - seen_ac_b0[key_ac_b0]);
            } else {
                seen_ac_b0[key_ac_b0] = i;
            }

            long long key_bc_a0 = (long long)(cb - cc) * mult2 + ca;
            if (seen_bc_a0.count(key_bc_a0)) {
                max_len = max(max_len, i - seen_bc_a0[key_bc_a0]);
            } else {
                seen_bc_a0[key_bc_a0] = i;
            }
        }

        return max_len;
    }
};