// Last updated: 19/08/2026, 15:31:36
// class Solution {
// public:
//     int partitionString(string s) {
//         int n = s.size();
//         if(n <= 1)return n;
//         unordered_set<char> st;
//         int cnt = 1;
//         for(int i=0; i<n; ++i){
//             if(st.count(s[i])){
//                 st.clear();
//                 cnt++;
//             }
//             st.insert(s[i]);
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        int cnt=1;
        int currstart=0;
        vector<int> prev(26,-1);
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(prev[ch-'a']>=currstart){
                cnt++;
                currstart=i;
            }
            prev[ch-'a']=i;
        }
    return cnt;
    }
};