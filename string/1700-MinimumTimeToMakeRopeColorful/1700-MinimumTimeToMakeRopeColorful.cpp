// Last updated: 19/08/2026, 15:38:50
// class Solution {
// public:
//     int minCost(string colors, vector<int>& neededTime) {
//         int n = colors.size();
//         int sum = 0;
//         for(int i=1; i<n; ++i){
//             int maxi = 0;
//             while(i<n && colors[i] == colors[i-1]){
//                 sum += neededTime[i-1];
//                 maxi = max(maxi,neededTime[i-1]);
//                 ++i;
//             }
//             sum += neededTime[i-1];
//             maxi = max(maxi,neededTime[i-1]);
//             if(maxi != 0)sum -= maxi;
//         }
//         return sum;
//     }
// };


// class Solution {
// public:
//     int minCost(string colors, vector<int>& neededTime) {
//         int n = colors.size();
//         int sum = 0;
//         for(int i=1; i<n; ++i){
//             if(colors[i] == colors[i-1]){
//                 sum += min(neededTime[i],neededTime[i-1]);
//                 neededTime[i] = max(neededTime[i],neededTime[i-1]);
//             }
//         }
//         return sum;
//     }
// };


class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        if(colors.size() == 1){
            return 0;
        }
        int i = 0;
        int j = i+1;
        int ans = 0;
        while(j<colors.size()){
            if(colors[i] == colors[j]){
                if(neededTime[i]<=neededTime[j]){
                    ans+=neededTime[i];
                    i=j;
                    j++;
                }
                else{
                    ans+=neededTime[j];
                    j++;
                }
            }
            else{
                i=j;
                j++;
            }
        }
        return ans;
    }
};