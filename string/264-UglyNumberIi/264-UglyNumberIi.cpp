// Last updated: 19/08/2026, 16:03:38
// class Solution {
// public:
//     bool f(int n){
//         if(n <=0)return false;
//         while(n%2 == 0)n/=2;
//         while(n%3 ==0)n/=3;
//         while(n%5 == 0)n/=5;
//         return (n==1);
//     }
// public:
//     int nthUglyNumber(int n) {
//         int cnt = 0;
//         for(int i=1; i<INT_MAX; ++i){
//             if(f(i))cnt++;
//             if(cnt == n)return i;
//         }
//         return -1;
//     }
// };

// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         vector<int> t(n+1);
//         t[1] = 1;
//         int i2;
//         int i3;
//         int i5;
//         i2 = i3 = i5 = 1;
//         for(int i=2; i<=n; ++i){
//             int i2ug = t[i2]*2;
//             int i3ug = t[i3]*3;
//             int i5ug = t[i5]*5;
//             t[i] = min({i2ug,i3ug,i5ug});
//             if(i2ug == t[i])i2++;
//             if(i3ug == t[i])i3++;
//             if(i5ug == t[i])i5++;

//         }
//         return t[n];
//     }
// };

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>ugly(n);
        ugly[0]=1;
        int i2=0,i3=0,i5=0;
        for(int i=1; i<n; i++){
            int next2=ugly[i2]*2;
            int next3=ugly[i3]*3;
            int next5=ugly[i5]*5;
            int next = min(next2, min(next3, next5));
            ugly[i]=next;
              if(next == next2) i2++;
    if(next == next3) i3++;
    if(next == next5) i5++;

        }
        return ugly[n-1];
    }
};