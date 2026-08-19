// Last updated: 19/08/2026, 16:01:53
// class Solution {
// public:
//     bool f(int mid,vector<int> &nums,int k){
//         int cs = 1;
//         int sm = 0;
//         for(int i : nums){
//             if(i + sm > mid){
//                 cs++;
//                 sm = i;
//             }else{
//                 sm += i;
//             }
//         }
//         if(cs <= k)return true;
//         else return false;
//     }
// public:
//     int splitArray(vector<int>& nums, int k) {
//         using ll = long long;
//         if(k > nums.size())return -1;
//         ll l = *max_element(nums.begin(),nums.end());
//         ll r = accumulate(nums.begin(),nums.end(),0);
//         ll ans = 1;
//         while(l <= r){
//             int mid = l + (r-l)/2;
//             if(f(mid,nums,k)){
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
    int countstudents(vector<int>&arr, int pages){
        int student=1,pagestud=0;
        for(int i=0;i<arr.size();i++){
            if(pagestud+arr[i]<=pages){
                pagestud+=arr[i];
            }
            else{
                pagestud=arr[i];
                student++;
            }
        }
        return student;
    }
    int findPages(vector<int> &nums, int m)  {
        int n=nums.size();
        if(m>n) return -1;
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int numstud=countstudents(nums,mid);
            if(numstud>m){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,k);
    }
};