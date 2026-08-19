// Last updated: 19/08/2026, 16:10:42
// // class Solution {
// // public:
// //     int mySqrt(int x) {
// //         int l = 0;
// //         int r = x;
// //         int ans = 0;
// //         while(l <= r){
// //             int mid = l + (r-l)/2;
// //             if(1LL*mid*mid <= x){
// //                 ans = mid;
// //                 l = mid + 1;
// //             }else{
// //                 r = mid-1;
// //             }
// //         }
// //         return ans;
// //     }
// // };
// class Solution {
// public:
//     int mySqrt(int x) {
//         long long l =1, h=x;
//         while(l<=h){
//             long long m =(l+h)/2;
//             if((long long)(m*m)<=x)    l=m+1;
//             else h=m-1;
//         }
//         return h;
//     }
// };

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;

        int l = 1, r = x;
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (mid <= x / mid) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};