// Last updated: 19/08/2026, 15:49:59
// class Solution {
// public:
//     bool f(int mid,vector<int> &nums,int t){
//         int c = 0;
//         for(int i : nums){
//             c += ((i+mid-1)/mid);
//         }
//         if(c <= t)return true;
//         else return false;
//     }
// public:
//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int l = 1;
//         int r = *max_element(nums.begin(),nums.end()) + 1;
//         int ans = -1;
//         while(l <= r){
//             int mid = l + (r-l)/2;
//             if(f(mid,nums,threshold)){
//                 ans = mid;
//                 r = mid -1;
//             }else{
//                 l = mid+1;
//             }
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     int smallestDivisor(vector<int>& nums, int threshold) {
//         if (nums.size() > threshold) return -1;
//         int hi=*max_element(nums.begin(),nums.end());
//         int lo=1;
//         while(lo<=hi){
//             int mid=(hi+lo)/2;
//             long long sum=0;
//             for(int i=0;i<nums.size();i++){
//                 sum+=(nums[i]+mid-1)/mid;
//             }
//             if(sum<=threshold) hi=mid-1;
//             else lo=mid+1;
//         }
//         return lo;
//     }
// };

// class Solution {
// public:
//     int sumbyD(vector<int> &nums, int div){
//         int sum = 0;
//         int n = nums.size();
//         for(int i  = 0; i<n; i++){
//             sum = sum + ceil((double)(nums[i]) / (double)(div));
//         }
//         return sum;
//     }
// public:
//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int n = nums.size();
//         if(n > threshold) return -1;
//         int low = 1 , high = *max_element(nums.begin(), nums.end());
//         while(low <= high){
//             int mid = (low + high) / 2;
//             if(sumbyD(nums , mid) <= threshold){
//                 high = mid - 1;
//             }
//             else{
//                 low = mid + 1;
//             }
//         }
//         return low;
//     }
// };

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            int sum=0;
            for(int num:nums){
                sum += (long long)(num + mid - 1) / mid;
            }
            if(sum<=threshold){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};