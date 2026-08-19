// Last updated: 19/08/2026, 16:07:28
// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings .size();
//         vector<int> lf(n,1);
//         vector<int> rf(n,1);
//         for(int i=1; i<n; ++i){
//             if(ratings[i] > ratings[i-1]){
//                 lf[i] = lf[i-1] + 1;
//             }
//         }
//         for(int i=n-2; i>=0; --i){
//             if(ratings[i] > ratings[i+1]){
//                 rf[i] = rf[i+1] + 1;
//             }
//         }
//         int cnt = 0;
//         for(int i=0; i<n; i++){
//             cnt += max(lf[i],rf[i]);
//         }
//         return cnt;
//     }
// };

// iterate right arr and max at the same time
// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings .size();
//         vector<int> lf(n,1);
//         for(int i=1; i<n; ++i){
//             if(ratings[i] > ratings[i-1]){
//                 lf[i] = lf[i-1] + 1;
//             }
//         }
//         int curr = 1, right = 1;
//         int sum = lf[n-1];
//         for(int i=n-2; i>=0; --i){
//             if(ratings[i] > ratings[i+1]){
//                curr = right + 1;
//                right = curr;
//             }else{
//                 curr = 1;
//                 right = 1;
//             }
//             sum += max(lf[i],curr);
//         }
//         return sum;
//     }
// };

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings .size();
        int sum = 1;
        int i = 1;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]){
                peak += 1;
                sum += peak;
                i++;
            }
            int down = 1;
            while(i < n && ratings[i] < ratings[i-1]){
                sum += down;
                down++;
                i++;
            }
            if(down > peak)sum += down - peak;
        }
        return sum;
    }
};