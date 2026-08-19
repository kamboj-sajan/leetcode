// Last updated: 19/08/2026, 15:31:04
// class Solution {
// public:
//     long long dividePlayers(vector<int>& skill) {
//         sort(skill.begin(),skill.end());
//         long long res = 0;
//         int n = skill.size();
//         if(n%2 == 1)return -1;
//         int sum = skill[0] + skill[n-1];
//         res += (skill[0]*skill[n-1]);
//         for(int i=1; i<n/2; ++i){
//             if(skill[i] + skill[n-i -1] != sum)return -1;
//             res += (skill[i]*skill[n-i-1]);
//         }
//         return res;
//     }
// };

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        vector<int> vec(1001,0);
        int sum = 0;
        for(int &s : skill){
            sum += s;
            vec[s]++;
        }
        int teams = n/2;
        if(sum % teams != 0) return -1;
        int target = sum/teams;
        long long chem = 0;
        for(int i = 0; i < n; i++){
            int currSkill = skill[i];
            if(vec[currSkill] == 0) continue;   // already paired
            vec[currSkill]--;                   // remove current player
            int remainSkill = target - currSkill;
            if(remainSkill < 0 || remainSkill > 1000 || vec[remainSkill] <= 0){
                return -1;
            }
            chem += 1LL * currSkill * remainSkill;
            vec[remainSkill]--;
        }
        return chem;
    }
};