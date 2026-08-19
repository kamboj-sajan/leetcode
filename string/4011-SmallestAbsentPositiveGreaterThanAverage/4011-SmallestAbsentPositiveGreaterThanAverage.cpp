// Last updated: 19/08/2026, 15:21:28
class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
     long long sum = 0;  
        unordered_set<int> st;
        for (int x : nums) {
            sum += x;
            st.insert(x);
        }
        long long avg = sum / (long long)nums.size();
        if (avg < 0) avg = 0;
        for (long long i = avg + 1; i <= avg + nums.size() + 1; i++) {
            if (!st.count((int)i)) {
                return (int)i;
            }
        }
        return -1;
    }
};