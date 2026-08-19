// Last updated: 19/08/2026, 15:36:41
// // class Solution {
// // public: 
// //     int ans = 0;
// //     void f(string &s){
// //         vector<int> vec(26,0);
// //         for(char &c : s){
// //             vec[c-'a']++;
// //         }
// //         int a = INT_MIN;
// //         int b = INT_MAX;
// //         for(int i=0; i<26; i++){
// //             if(vec[i] > 0){
// //             a = max(vec[i],a);
// //             b = min(vec[i],b);
// //             }
// //         }
// //         ans += (a-b);
// //     }
// // public:
// //     int beautySum(string s) {
// //         int n = s.size();
// //         for(int i=0; i<n; i++){
// //             for(int j=i; j<n; j++){
// //                 string d = s.substr(i,j-i+1);
// //                 f(d);
// //             }
// //         }
// //         return ans;
// //     }
// // };

// // class Solution {
// // public:
// //     int beautySum(string s) {
// //         int n = s.size();
// //         vector<int> vec(26,0);
// //         int cnt = 0;
// //         for(int i=0; i<n; i++){
// //             fill(vec.begin(),vec.end(),0);
// //             for(int j=i; j<n; j++){
// //                 vec[s[j] - 'a']++;
// //                 int maxi = INT_MIN;
// //                 int mini = INT_MAX;
// //                 for(int k=0; k<26; k++){
// //                     if(vec[k] > 0){
// //                     maxi = max(maxi,vec[k]);
// //                     mini = min(mini,vec[k]);
// //                     }
// //                 }
// //                 cnt += maxi-mini;
// //             }
// //         }
// //         return cnt;
// //     }
// // };

// class Solution {
// public:
//     int beautySum(string s) {
//         int n = s.size();
//         vector<int> vec(26,0);
//         int cnt = 0;
//         for(int i=0; i<n; i++){
//             fill(vec.begin(),vec.end(),0);
//             for(int j=i; j<n; j++){
//                 vec[s[j] - 'a']++;
//                 int maxi = INT_MIN;
//                 int mini = INT_MAX;
//                 for(int k=0; k<26; k++){
//                     if(vec[k] > 0){
//                     maxi = max(maxi,vec[k]);
//                     mini = min(mini,vec[k]);
//                     }
//                 }
//                 cnt += maxi-mini;
//             }
//         }
//         return cnt;
//     }
// };

// class Solution {
// public: 
//     int beauty(string s){
//        unordered_map<char,int> mpp;
//        for(char &p : s){
//         mpp[p]++;
//        } 
//        int maxi = INT_MIN;
//        int mini = INT_MAX;
//        for(auto kp : mpp){
//         maxi = max(maxi,kp.second);
//         mini = min(mini,kp.second);
//        }
//        mpp.clear();
//        return (maxi-mini);
//     }
// public:
//     int beautySum(string s) {
//         int cnt = 0;
//         for(int i=0; i<s.size(); i++){
//             for(int j=i; j<s.size(); j++){
//                 cnt += beauty(s.substr(i,j-i+1)); // substr(pos,len)
//             }
//         }
//         return cnt;
//     }
// };tle;

// class Solution {
// public:
//     int beauty(const string &s) {
//         unordered_map<char, int> mpp;
//         for (char c : s) {
//             mpp[c]++;
//         }
//         int maxi = 0, mini = INT_MAX;
//         for (auto &kv : mpp) {
//             maxi = max(maxi, kv.second);
//             mini = min(mini, kv.second);
//         }
//         return maxi - mini;
//     }

//     int beautySum(string s) {
//         int cnt = 0;
//         for (int i = 0; i < s.size(); i++) {
//             for (int j = i; j < s.size(); j++) {
//                 cnt += beauty(s.substr(i, j - i + 1));
//             }
//         }
//         return cnt;
//     }
// };
//tle

// class Solution {
// public:
//     int getmin(const vector<int> &freq) {
//         int mini = INT_MAX;
//         for (int i = 0; i < 26; ++i) {
//             if (freq[i] != 0) {
//                 mini = min(mini, freq[i]);
//             }
//         }
//         return mini;
//     }

//     int getmax(const vector<int> &freq) {
//         int maxi = 0;
//         for (int i = 0; i < 26; ++i) {
//             maxi = max(maxi, freq[i]);
//         }
//         return maxi;
//     }

//     int beautySum(string s) {
//         int sum = 0;
//         for (int i = 0; i < s.size(); ++i) {
//             vector<int> freq(26, 0);
//             for (int j = i; j < s.size(); ++j) {
//                 freq[s[j] - 'a']++;
//                 int beauty = getmax(freq) - getmin(freq);
//                 sum += beauty;
//             }
//         }
//         return sum;
//     }
// };


class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;
        for(int i =0;i<n;i++){
            unordered_map<char, int> mp;
            
            for(int j = i;j<n;j++){ 
                mp[s[j]]++;
                int maxFreq = INT_MIN;
                int minFreq = INT_MAX;
                for(auto it: mp){
                    maxFreq = max(maxFreq, it.second);
                    minFreq = min(minFreq, it.second);

                }

                sum += maxFreq - minFreq;
            }
        }
        return sum;
    }
};