// Last updated: 19/08/2026, 15:20:24
// class Solution {
// public:
//     long long countMajoritySubarrays(vector<int>& nums, int target) {
//         using ll = long long;
//         int n = nums.size();
//         ll ans = 0;
//         for(int i=0; i<n; ++i){
//             int k = 0;
//             for(int j=i; j<n; ++j){
//                 if(nums[j] == target)k++;
//                 int len = j-i+1;
//                 if(k * 2 > len)ans++;
//             }
//         }
//         return ans;
//     }
// }; tle

// class Solution {
// public:
//     long long countMajoritySubarrays(vector<int>& nums, int target) {
//         using ll = long long;
//         int n = nums.size();
//         ll ans = 0;
//         for(int i=0; i<n; ++i){
//             int k = 0;
//             for(int j=i; j<n; ++j){
//                 k += (nums[j] == target)? +1 : -1;
//                 if(k > 0)ans++;
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     long long countMajoritySubarrays(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<int> pre(n + 1, 0);
//         for (int i = 0; i < n; i++) {
//             pre[i + 1] = pre[i] + (nums[i] == target ? 1 : -1);
//         }
//         long long ans = 0;
//         for (int l = 0; l < n; l++) {
//             for (int r = l; r < n; r++) {
//                 if (pre[r + 1] - pre[l] > 0)
//                     ans++;
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     long long countMajoritySubarrays(vector<int>& nums, int target) {
//         int n = nums.size();
//         unordered_map<int,int> mpp; //cumsum -> count;
//         int cumsum = 0;
//         mpp[0] = 1;
//         using ll = long long;
//         ll validleftpoints = 0;
//         ll ans = 0;
//         for(int i=0; i<n; ++i){
//             if(nums[i] == target){
//                 validleftpoints += mpp[cumsum];
//                 cumsum += 1;
//             }else{
//                 cumsum -= 1;
//                 validleftpoints -= mpp[cumsum];
//             }
//             mpp[cumsum] += 1;
//             ans += validleftpoints;
//         }
//         return ans;
//     }
// };

constexpr int N=2e5+2;
long long cntB[N], bias;

class Solution {
public:
    static long long countMajoritySubarrays(vector<int>& nums, int target) 
    {
        bias=nums.size()+1;
        int balance=bias;
        
        memset(cntB ,0, (2*bias)*sizeof(long long));
        cntB[balance]=1;
        long long ans=0, sum=0;
        
        for (int x : nums) {
            if (x==target) sum+=cntB[balance++];
            else sum-=cntB[--balance];
            
            cntB[balance]++;
            ans+=sum;
        }
        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();