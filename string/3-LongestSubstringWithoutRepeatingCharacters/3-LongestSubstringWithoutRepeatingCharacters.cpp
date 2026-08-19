// Last updated: 19/08/2026, 16:14:27
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         if (n <= 1) return n;
//         int i = 0, j = 0;
//         int maxi = 1;
//         unordered_set<char> st;
//         while (j < n) {
//             if (st.find(s[j]) != st.end()) {
//                 while (i < j) {
//                     char ch = s[i];
//                     st.erase(ch);
//                     i++;

//                     if (ch == s[j]) break;
//                 }
//             }
//             st.insert(s[j]);
//             maxi = max(maxi, j - i + 1);
//             j++;
//         }
//         return maxi;
//     }
// };

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         int i = 0, j = 0;
//         int maxi = 0;
//         unordered_set<char> st;
//         while (j < n) {
//             while (st.count(s[j])) {
//                 st.erase(s[i]);
//                 i++;
//             }
//             st.insert(s[j]);
//             maxi = max(maxi, j - i + 1);
//             j++;
//         }
//         return maxi;
//     }
// };

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         vector<int> last(256, -1);
//         int ans = 0;
//         int left = 0;
//         for (int right = 0; right < s.size(); right++) {
//             if (last[s[right]] >= left) {
//                 left = last[s[right]] + 1;
//             }
//             last[s[right]] = right;
//             ans = max(ans, right - left + 1);
//         }
//         return ans;
//     }
// };

class Solution {
public:

    bool check(int mid, string s){
        vector <int> cnt (256);
        int uni = 0;
        for(int i =0 ; i < mid ; i++){
            if (cnt[s[i]] == 0)uni++;
            cnt[s[i]]++;
        }
        if (uni == mid) return true;

        for (int i = mid ; i < s.size() ; i++){
            cnt[s[i- mid]]--;
            if (cnt[s[i-mid]]== 0) uni--;

            if (cnt[s[i]] == 0) uni ++;
            cnt[s[i]]++;

            if (uni == mid) return true;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0) return 0;
        int l = 1, h = n+1;
        int mid;
        while(h - l > 1){
            mid = l + (h-l)/2;
            if (check(mid, s)) l = mid;
            else h = mid;
            }
            return l ;
        }
    
};