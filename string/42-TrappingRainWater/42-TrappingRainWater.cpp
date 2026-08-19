// Last updated: 19/08/2026, 16:12:12
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         vector<int> ge;
//         vector<int> ge2;
//         int k;
//        for(int i=0; i<n; i++){
//         int maxi = INT_MIN;
//         int maxi2 = INT_MIN;
//         k = n-1-i;
//         for(int j=i+1; j<n; j++){
//             maxi = max(maxi,height[j]);
//         }
//         ge.push_back(maxi);
//         for(int l=k-1; l>=0; l--){
//             maxi2 = max(maxi2,height[l]);
//         }
//         ge2.push_back(maxi2);
//        }
//        reverse(ge2.begin(),ge2.end());
//        long el;
//        long long rainwater = 0;
//        for(int i=0; i<n; i++){
//         el = min(ge[i],ge2[i]);
//          if (el > height[i]) {  
//                 rainwater += el - height[i];
//             }
//        }
//        return (int)rainwater;
//     } 
// };
// tle 322/324
// intuition see largest element from both sides and take min from both
// if this > height[i];
// rainwater + this;

// class Solution {
// public:
//     int prefixMax(int ind,vector<int> &height){
//         int n = height.size();
//         vector<int> prefix(n);
//         prefix[0] = height[0];
//         for(int i=1; i<n; i++){
//             prefix[i] = max(prefix[i-1],height[i]);
//         }
//         return prefix[ind];
//     }
//     int suffixMax(int ind,vector<int> &height){
//         int n = height.size();
//         vector<int> suffix(n);
//         suffix[n-1] = height[n-1];
//         for(int i=n-2; i>=0; i--){
//             suffix[i] = max(suffix[i+1],height[i]);
//         }
//         return suffix[ind];
//     }
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int total = 0;
//         for(int i=0; i<n; i++){
//             int leftmax = prefixMax(i,height);
//             int rightmax = suffixMax(i,height);
//             if(height[i] < leftmax && height[i] < rightmax){
//                 total += min(leftmax,rightmax) - height[i];
//             }
//         }
//         return total;
//     } 
// };
// tle 320/324

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         vector<int> suffix(n);
//         suffix[n - 1] = height[n - 1];
//         for(int i = n - 2; i >= 0; i--) {
//             suffix[i] = max(suffix[i + 1], height[i]);
//         }
//         int leftMax = 0;
//         int ans = 0;
//         for(int i = 0; i < n; i++) {
//             leftMax = max(leftMax, height[i]);

//             ans += min(leftMax, suffix[i]) - height[i];
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n=height.size();
//         vector<int>left(n),right(n);
//         left[0]=height[0];
//         for(int i=1;i<n;i++){
//             left[i]=max(left[i-1],height[i]);
//         }
//         right[n-1]=height[n-1];
//         for(int i=n-2;i>=0;i--){
//             right[i]=max(right[i+1],height[i]);
//         }
//         int ans=0;
//         for(int i=0;i<n;i++){
//             ans+=min(left[i],right[i])-height[i];
//         }
//         return ans;
//     }
    /*
    0 1 1 2 2 2 2 3 3 3 3 3 
    3 3 3 3 3 3 3 3 2 2 2 1
    0 1 1 2 2 2 2 3 2 2 2 1
    0 0 1 0 1 2 1 0 0 1 0 0


    4 4 4 4 4 5
    5 5 5 5 5 5
    4 4 4 4 4 5
    0 2 4 1 2 0
    */
// };

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = 0, rmax = 0;
        int total = 0;
        int l = 0;
        int r = n-1;
        while(l < r){
            if(height[l] <= height[r]){
                if(lmax > height[l]){
                    total += lmax - height[l];
                }
                else{
                    lmax = height[l];
                }
                l = l + 1;
            }else{
                if(rmax > height[r]){
                    total += rmax - height[r];
                }else{
                    rmax = height[r];
                }
                 r = r-1;
            }
        }
        return total;
    } 
};