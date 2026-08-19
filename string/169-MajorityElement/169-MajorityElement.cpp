// Last updated: 19/08/2026, 16:06:09
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         /*
//         map<int,int> mpp;
//         for(int i=0; i<nums.size(); i++){
//             mpp[nums[i]]++;
//         }
//         for(auto it : mpp){
//             if(it.second > (nums.size()/2)){
//                 return it.first;
//             }
//         }
//         return -1;
//         */
//         int cnt = 0;
//         int el;
//         int n = nums.size();
//         for(int i = 0; i<n; i++){
//             if(cnt == 0){
//                 cnt = 1;
//                 el = nums[i];
//             }else if(nums[i] == el){
//                 cnt++;
//             }else{
//                 cnt--;
//             }
//         }
//         int cnt1 = 0;
//         for(int i = 0; i<n; i++){
//             if(nums[i] == el) cnt1++;
//         }
//         if(cnt1 > n/2){
//             return el;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int mid=(i+j)/2;
        return nums[mid];
    }
};