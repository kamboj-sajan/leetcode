// Last updated: 19/08/2026, 15:54:34
// class Solution {
// public:
//     int f(int i,vector<int>& days, vector<int>& costs,vector<int> &dp){
//         if(i >= days.size()){
//             return 0;
//         }
//         if(dp[i] != -1)return dp[i];
//         int one = lower_bound(days.begin(),days.end(),days[i]+1) - days.begin();
//         int week = lower_bound(days.begin(),days.end(),days[i]+7) - days.begin();
//         int month = lower_bound(days.begin(),days.end(),days[i]+30) - days.begin();
//         int a = f(one,days,costs,dp) + costs[0];
//         int b = f(week,days,costs,dp) + costs[1];
//         int c = f(month,days,costs,dp) + costs[2];
//         return dp[i] = min(a,min(b,c));
//     }
// public:
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         vector<int> dp(days.size(),-1);
//         return f(0,days,costs,dp);;
//     }
// };

// class Solution {
// public:
//     int dp[366];
//     int min_cost(int day,int max_day , set<int>& st, vector<int>& costs,vector<int>& pass){
//         if(day>max_day){
//             return 0;
//         }
//         if(dp[day]!=-1) return dp[day];

//         int ans = INT_MAX;
//         for(int i = 0 ; i<4 ; i++){
//             if(i == 3){
//                 if(!st.contains(day)) ans = min(ans,min_cost(day+1,max_day,st,costs,pass));
//                 else break;
//             }

//             else ans = min(ans,costs[i] + min_cost(day+pass[i],max_day,st,costs,pass));
//         }
//         return dp[day]=ans;
//     }
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         memset(dp,-1,sizeof(dp));
//         int n = days.size();
//         set<int> st;
//         vector<int> pass = {1,7,30};
//         for(int i = 0 ; i<n ; i++){
//             st.insert(days[i]);
//         }
//         int max_day = *st.rbegin();
//         return min_cost(1,max_day,st,costs,pass);
//     }
// };

class Solution {
public:
    int dp[366];
    int min_cost(int idx,vector<int>& days, map<int,int> & mp, vector<int>& costs,vector<int>& pass){
        if(idx==-1){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];

        int ans = INT_MAX;
        for(int i = 0 ; i<3 ; i++){
            int id = -1;
            auto it = mp.upper_bound(days[idx]+pass[i]-1);
            if(it != mp.end()) id = mp[it->first];
            ans = min(ans,costs[i] + min_cost(id,days,mp,costs,pass));
        }
        return dp[idx]=ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        int n = days.size();
        map<int,int> mp;
        vector<int> pass = {1,7,30};
        for(int i = 0 ; i<n ; i++){
            mp[days[i]] = i;
        }
        return min_cost(0,days,mp,costs,pass);
    }
};