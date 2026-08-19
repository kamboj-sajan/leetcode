// Last updated: 19/08/2026, 15:28:27
// class Solution {
// public:
//     long long maximumHappinessSum(vector<int>& happiness, int k) {
//         int n = happiness.size();
//         int cnt = 0;
//         priority_queue<int> pq;
//         for(int i=0; i<n; ++i){
//             pq.push(happiness[i]);
//         }
//         int b = INT_MAX;
//         int c = k;
//         long long sum = 0;
//         while(!pq.empty() && b>0 && c>0){
//             int d = pq.top();
//             pq.pop();
//             b = d - cnt;
//             cnt++;
//             if(b > 0)sum += b;
//             c--;
//         }
//         return sum;
//     }
// };

// class Solution {
// public:
//     long long maximumHappinessSum(vector<int>& happiness, int k) {
//         priority_queue<int> pq;
//         for (int x : happiness) pq.push(x);
//         long long sum = 0;
//         int cnt = 0;
//         while (k-- && !pq.empty()) {
//             int d = pq.top();
//             pq.pop();

//             int b = d - cnt;
//             if (b > 0) sum += b;

//             cnt++;
//         }
//         return sum;
//     }
// };


using namespace std;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin() , happiness.rend());
        int n = happiness.size();
        int h = 0 ;
        long long ct = 0 ;
        long long ans = 0;
        while(k-- and h<n){
            if(happiness[h]-ct<=0)break;
            long long val = max(0LL,happiness[h] - ct);
            ans+=val;
            ct++;
            h++;
        }
        return ans;
    }
};