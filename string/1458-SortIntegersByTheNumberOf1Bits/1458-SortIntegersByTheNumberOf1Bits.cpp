// Last updated: 19/08/2026, 15:49:09
class Solution {
public:
    int countBits(int n) {
    return __builtin_popcount(n);   // GCC inbuilt function
}
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
        int bitsA = __builtin_popcount(a);
        int bitsB = __builtin_popcount(b);

        // first condition: compare number of 1's
        if (bitsA == bitsB)
            return a < b;   // second condition: smaller number first

        return bitsA < bitsB;
    });

    return arr;
    }
};