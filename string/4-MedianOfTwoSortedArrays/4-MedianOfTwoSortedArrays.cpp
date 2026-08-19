// Last updated: 19/08/2026, 16:14:23
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         if(nums2.size() < nums1.size())return findMedianSortedArrays(nums2,nums1);
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         int l = 0;
//         int h = n1;
//         while(l <= h){
//             int cut1 = l+ (h-l)/2;
//             int cut2 = (n1+n2+1)/2 - cut1;
//             int lf1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
//             int lf2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
//             int rf1 = cut1 == n1 ? INT_MAX : nums1[cut1];
//             int rf2 = cut2 == n2 ? INT_MAX : nums2[cut2];
//             if(lf1 <= rf2 && lf2 <= rf1){
//                 if((n1+n2)%2 == 0)return (max(lf1,lf2)+min(rf1,rf2))/2.0;
//                 else return max(lf1,lf2);
//             }else if(lf1 > rf2){
//                 h = cut1-1;
//             }else{
//                 l = cut1+1;
//             }
//         }
//         return 0.0;
//     }
// };

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        long long i=0;
        long long j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size()) {
            ans.push_back(nums1[i]);
            i++;
        }
          while (j < nums2.size()) {
            ans.push_back(nums2[j]);
            j++;
        }
       
        int n=ans.size();
        if(n%2!=0){
            return ans[n/2];
        }
        else{
            return (ans[n/2]+ans[n/2-1])/2.0;
        }
    }
};