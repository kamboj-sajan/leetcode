// Last updated: 19/08/2026, 15:36:21
// class Solution {
// public:
//     int maximumElementAfterDecrementingAndRearranging(vector<int>& vec) {
//         int n = vec.size();
//         if(n == 1)return 1;
//         sort(vec.begin(),vec.end());
//         vec[0] = 1;
//         for(int i=1; i<n; i++){
//             if(vec[i] > vec[i-1] + 1){
//                 vec[i] = vec[i-1] + 1;
//             }
//         }
//         return vec[n-1];
//     }
// };

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();

        vector<int> cnt(n + 1);

        for (int x : arr)
            cnt[min(x, n)]++;

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            ans = min(i, ans + cnt[i]);
        }

        return ans;
    }
};