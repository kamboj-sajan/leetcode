// Last updated: 19/08/2026, 15:47:18
// class Solution {
// public:
//     bool f(int d,vector<int> &vec,int m,int k){
//         int c = 0;
//         int bc = 0;
//         for(int i : vec){
//             if(i <= d){
//                 c++;
//                 if(c == k){
//                     bc++;
//                     c=0;
//                 }
//             }else{
//                 c = 0;
//             }
//         }
//         if(bc >= m)return true;
//         else return false;
//     }
// public:
//     int minDays(vector<int>& bloomDay, int m, int k) {
//         int n = bloomDay.size();
//         if(1LL*m*k > n)return -1;
//         int l = *min_element(bloomDay.begin(),bloomDay.end());
//         int r = *max_element(bloomDay.begin(),bloomDay.end());
//         int ans = -1;
//         while(l <= r){
//             int mid = l + (r-l)/2;
//             if(f(mid,bloomDay,m,k)){
//                 ans = mid;
//                 r = mid-1;
//             }else{
//                 l = mid+1;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k> bloomDay.size()) return -1;

        int maxi = INT_MIN;
        for(int i = 0;i < n;i++) maxi = max(maxi,bloomDay[i]);

        int low = 0, high = maxi;
        while(low <= high){
            int mid = low + (high-low)/2;//no days passed

            int cnt = 0,bq=0;
            for(int i = 0; i < n;i++){
                if(bloomDay[i]<=mid){
                    cnt++;
                }else cnt = 0;
                if(cnt==k){
                    bq++;
                    cnt = 0;
                }
            }
            
            if(bq>=m) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};