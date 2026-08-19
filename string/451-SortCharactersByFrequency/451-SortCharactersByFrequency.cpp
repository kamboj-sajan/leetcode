// Last updated: 19/08/2026, 16:01:27
// // // class Solution {
// // // public:
// // //     string frequencySort(string s) {
// // //         vector<int> ch(26,0);
// // //         for(char c : s){
// // //             ch[c-'a']++;
// // //         }
// // //         sort(s.begin(),s.end(),[&](char a,char b){
// // //             if(ch[a-'a'] == ch[b-'a']){
// // //                 return a > b;
// // //             }else{
// // //                 return ch[a-'a']>ch[b-'a'];
// // //             }
// // //         });
// // //         return s;
// // //     }
// // // }; lowercase

// // class Solution {
// // public:
// //     string frequencySort(string s) {
// //         vector<int> ch(256, 0);
// //         for(char c : s){
// //             ch[(unsigned char)c]++;
// //         }
// //         sort(s.begin(), s.end(), [&](char a, char b){
// //             if(ch[(unsigned char)a] == ch[(unsigned char)b]){
// //                 return a > b;
// //             }
// //             return ch[(unsigned char)a] > ch[(unsigned char)b];
// //         });
// //         return s;
// //     }
// // };

// // class Solution {
// // public:
// //     string frequencySort(string s) {
// //         unordered_map<char,int> mpp;
// //         for(int i=0; i<s.size(); ++i){
// //             mpp[s[i]]++;
// //         }
// //         vector<pair<char,int>> vec(mpp.begin(), mpp.end());
// //         sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
// //         return a.second > b.second;
// //     });
// //         string ans = "";
// //         for(auto &p : vec){
// //             ans.append(p.second,p.first); // p.first number ki p.second values lag jaaye
// //         }
// //         return ans;
// //     }
// // };

// // class Solution {
// // public:
// //     string frequencySort(string s) {
// //         unordered_map<char,int> mpp;
// //         priority_queue<pair<int,char>> heap;
// //         for(auto ch:s)mpp[ch]++;
// //         for(auto [ch,freq] : mpp){
// //             heap.push({freq,ch});
// //         }
// //         string ans;
// //         while(!heap.empty()){
// //             for(int i=0; i<heap.top().first; ++i){
// //                 ans += heap.top().second;
// //             }
// //             heap.pop();
// //         }
// //         return ans;
// //     }
// // };

// class Solution {
// private:
//     bool static comparator(pair<char,int> p1,pair<char,int> p2){
//         if(p1.second!=p2.second){
//             return p1.second>p2.second;
//         }
//         return p1.first<p2.first;
//     }
// public:
//     string frequencySort(string s) {
//         unordered_map<char,int> mpp;
//         for(char ch:s) mpp[ch]++;
//         vector<pair<char,int>> freq(mpp.begin(),mpp.end());
//         sort(freq.begin(),freq.end(),comparator);
//         string ans;
//         for(auto itr:freq){
//             if(itr.second>0){
//                 ans+=string(itr.second,itr.first);
//             }
//             else break;
//         }
//         return ans;
//     }
// };

class Solution {
public:
typedef pair<char,int>P;
struct lambda{
    bool operator()(P &p1, P &p2){
        return p1.second < p2.second; //heap => top will have max freq entry 
    }
};
    string frequencySort(string s) {
        priority_queue<P,vector<P>, lambda>pq;
        unordered_map<char, int>mp;
        
        for(char &ch : s){
            mp[ch]++;
        }

        for(auto &it : mp){
            pq.push({it.first, it.second});
        }

        string result = "";
        while(!pq.empty()){
            P temp = pq.top();
            pq.pop();
            result += string(temp.second, temp.first);
        }
        return result;
    }
};