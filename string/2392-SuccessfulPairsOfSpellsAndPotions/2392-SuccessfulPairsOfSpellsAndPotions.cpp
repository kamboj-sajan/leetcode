// Last updated: 19/08/2026, 15:31:51
// class Solution {
// public:
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         vector<int> ans;
//         int len = spells.size();
//         int i = 0;
//         while(i < len){
//             int j = 0;
//             for(int k=0; k<potions.size(); ++k){
//                 if(spells[i]*potions[k] >= success){
//                     ++j;
//                 }
//             }
//             ans.push_back(j);
//             ++i;
//         }
//         return ans;
//     }
// };
// 48/57 spells[i]*potions[k] > int 

// class Solution {
// public:
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         vector<int> ans;
//         int len = spells.size();
//         for (int i = 0; i < len; ++i) {
//             int j = 0;
//             for (int k = 0; k < potions.size(); ++k) {
//                 if ((long long)spells[i] * potions[k] >= success) {
//                     ++j;
//                 }
//             }
//             ans.push_back(j);
//         }
//         return ans;
//     }
// };
// 51/57 tle


class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
       sort(potions.begin(),potions.end());
       int n = potions.size();
       vector<int> ans;
       for(int s : spells){
        long long d = (success + s - 1)/s;
        int ind = lower_bound(potions.begin(),potions.end(),d) - potions.begin();
        ans.push_back(n - ind);
       }
       return ans;
    }
};




