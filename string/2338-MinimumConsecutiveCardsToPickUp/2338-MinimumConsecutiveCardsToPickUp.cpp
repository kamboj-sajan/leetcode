// Last updated: 19/08/2026, 15:32:11
// class Solution {
// public:
//     int minimumCardPickup(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> freq(1000001,0);
//         int ans = INT_MAX;
//         int cnt = 0;
//         int l = 0;
//         for(int i=0; i<n; ++i){
//             freq[nums[i]]++;
//             cnt++;
//             if(freq[nums[i]] > 1){
//             while(freq[nums[i]] > 1){
//                 freq[nums[l]]--;
//                 cnt--;
//                 l++;
//             }
//              ans = min(ans,cnt+1);
//             }
//         }
//         return ans == INT_MAX ? -1 : ans;
//     }
// };

// class Solution {
// public:
// int minimumCardPickup(vector<int>& cards) {
//     int last[1000001] = {}, res = INT_MAX;
//     for (int i = 0; i < cards.size(); ++i) {
//         if (last[cards[i]])
//             res = min(res, i - last[cards[i]] + 2);
//         last[cards[i]] = i + 1;
//     }
//     return res == INT_MAX ? -1 : res;
// }
// };

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> last;
        int ans = INT_MAX;

        for (int i = 0; i < cards.size(); i++) {
            if (last.count(cards[i])) {
                ans = min(ans, i - last[cards[i]] + 1);
            }
            last[cards[i]] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};