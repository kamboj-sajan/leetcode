// Last updated: 19/08/2026, 15:27:31
// class Solution {
// public: 
//     bool f(int mountainHeight,vector<int> &vec,long long T){
//         ll tot = 0;
//         for(int t : vec){
//             // Solve: t * x*(x+1)/2 <= T
//             ll val = (2 * T)/t;
//             ll x = (sqrt(1 + 4 * val) - 1)/2;
//             tot += x;
//             if(tot >= mountainHeight)return true;
//         }
//         return false;
//     }
// public:
//     using ll = long long;
//     long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
//         ll l = 0;
//         ll r = 1LL * (*max_element(workerTimes.begin(),workerTimes.end())) * mountainHeight * (mountainHeight + 1) / 2;
//         while(l < r){
//             ll mid = l + (r-l) / 2;
//             if(f(mountainHeight,workerTimes,mid)){
//                 r = mid;
//             }else{
//                 l = mid + 1;
//             }
//         }
//         return l;
//     }
// };

class Solution {
public:
    // TC O(n * log(maxTime * H^2)) 
    // SC O(1)
    bool check(long long mid, int mountainHeight, vector<int>& workerTimes){
        long long height=0;
        for(int time : workerTimes){
            height+=(long long)(sqrt(2*mid/time+0.25)-0.5);
            if(height>=mountainHeight) return true;
        }
        return height>=mountainHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxTime=*max_element(workerTimes.begin(),workerTimes.end());
        long long lo=1;
        long long hi=(long long)maxTime*mountainHeight*(mountainHeight+1)/2;
        long long result=0;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            if(check(mid,mountainHeight,workerTimes)){
                result=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return result;
    }
};