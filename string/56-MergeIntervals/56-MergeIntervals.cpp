// Last updated: 19/08/2026, 16:11:20
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //    int n = intervals.size();
    //    if(n == 0)return {};
    //    sort(intervals.begin(),intervals.end(),[](auto &a, auto &b){
    //     return a[0] < b[0];
    //    });
    //    vector<vector<int>> ans;
    //    int i = 0;
    //    while(i < n){
    //     int pi = i;
    //     int j = i;
    //     while(j < n-1 && intervals[j][1] >= intervals[j+1][0]){
    //         intervals[j+1][0] = min(intervals[j][0],intervals[j+1][0]);
    //         intervals[j+1][1] = max(intervals[j][1],intervals[j+1][1]);
    //         j++;
    //     }
    //     ans.push_back({intervals[pi][0],intervals[j][1]});
    //     i = j+1;
    //    }
    //    return ans;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        if(intervals.empty()) return {};
//         sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
//             return a[0] < b[0];
//         });

//         vector<vector<int>> ans;
//         ans.push_back(intervals[0]);

//         for(int i = 1; i < intervals.size(); i++) {
//             if(intervals[i][0] <= ans.back()[1]) {
//                 ans.back()[1] = max(ans.back()[1], intervals[i][1]);
//             } else {
//                 ans.push_back(intervals[i]);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int size=intervals.size();
        sort(intervals.begin(),intervals.end());

        int a=intervals[0][0];
        int b=intervals[0][1];
        for(int i=1; i<size; i++){
            if(intervals[i][0]<=b){
                b=max(b,intervals[i][1]);
            }

            if(intervals[i][0]>b){
                ans.push_back({a,b});
                a=intervals[i][0];
                b=intervals[i][1];
            }

        }

        ans.push_back({a,b});

        return ans;
        
    }
};