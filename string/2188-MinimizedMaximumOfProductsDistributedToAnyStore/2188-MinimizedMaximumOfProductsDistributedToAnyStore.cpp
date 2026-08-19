// Last updated: 19/08/2026, 15:33:38
// class Solution {
// public:
//     bool f(int n,vector<int> &vec,int mid){
//         int a = 0;
//         for(int i : vec){
//             a += ((i+mid-1)/mid);
//             if(a > n)return false;
//         }
//         return true;
//     }
// public:
//     int minimizedMaximum(int n, vector<int>& quantities) {
//         int l = 1;
//         int r = *max_element(quantities.begin(),quantities.end());
//         int ans = 0;
//         while(l <= r){
//             int mid = l + (r-l)/2;
//             if(f(n,quantities,mid)){
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
    bool isPossible(int n, vector<int>& quantities, int mid, int s){
        if(mid == 0)
            return false;
        int count = 0;
        for(int i=0; i<s; i++){
            count += quantities[i]/mid;
            if(quantities[i] % mid)
                count++;
        }
        if(count <= n)
            return true;
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxi = INT_MIN, s = quantities.size();
        for(int i=0; i<s; i++)
            maxi = max(maxi, quantities[i]);
        int left = 0, right = maxi, ans = INT_MAX;
        vector<int> possible;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(isPossible(n, quantities, mid, s)){
                possible.push_back(mid);
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        int p = possible.size();
        for(int i=0; i<p; i++)
            ans = min(ans, possible[i]);
        return ans;
    }
};