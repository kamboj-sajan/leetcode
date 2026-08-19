// Last updated: 19/08/2026, 15:29:13
// class Solution {
// public:
//     int missingInteger(vector<int>& nums) {
//         int ans = nums[0];
//         for(int i=1; i<nums.size(); i++){
//             if(nums[i] == nums[i-1]+1){
//                 ans += nums[i];
//             }else break;
//         }
//         unordered_set<int> st(nums.begin(),nums.end());
//         for(int i = ans; i<INT_MAX; i++){
//             if(st.find(i) == st.end()){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int i=1,sum=nums[0];
        int n=nums.size();
        while(i<n){
            if((nums[i]-nums[i-1])==1){
                sum+=nums[i++];
            }else{
                break;
            }
        }
        bool flag=true;
        while(true){
            for(int j=i-1;j<n;j++){
                if(sum==nums[j]){
                    flag=false;
                    break;
                }
            }
            
            if(flag==true){
                return sum;
            }else {
                flag=true;sum++;
            }
        }
        return 0;
        
    }
};