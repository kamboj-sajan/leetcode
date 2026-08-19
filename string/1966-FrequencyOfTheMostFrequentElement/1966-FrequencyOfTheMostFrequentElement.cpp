// Last updated: 19/08/2026, 15:36:14
// class Solution {
// public:
//     int maxFrequency(vector<int>& nums, int k) {
//         int n = nums.size();
//         int ans = INT_MIN;
//         sort(nums.begin(),nums.end(),greater<int>());
//         for(int i=0; i<n; ++i){
//             int dif = 0;
//             for(int j=i; j<n; ++j){
//                 dif += (nums[i] - nums[j]);
//                 if(dif <= k)ans = max(ans,j-i+1); 
//             }
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     int maxFrequency(vector<int>& nums, int k) {
//         int n = nums.size();
//         using ll = long long;
//         sort(nums.begin(),nums.end());
//         int i =0;
//         ll sum = 0;
//         int ans = INT_MIN;
//         for(int j=0; j<n; ++j){
//             sum += nums[j];
//             while((ll)nums[j]*(j-i+1) - sum > k){
//                 sum -= nums[i];
//                 i++;
//             }
//             ans = max(ans,j-i+1);
//         }
//         return ans;
//     }
// };

// class Solution {
//     const static int maxValue = 1e5;
//     inline static int freq[maxValue + 1];
// public:
//     // Solution 2: Counting Sort + Sliding Window
//     int maxFrequency(vector<int>& nums, int k) {
//         const int n = nums.size();
//         long long res = 0, left = 0, right = 0, windowSum = 0;
//         memset(freq, 0, sizeof(freq));
//         int minVal = 1e9, maxVal = 0;
//         for(int i = 0; i < n; i++){
//             minVal = min(minVal, nums[i]);
//             maxVal = max(maxVal, nums[i]);
//             freq[nums[i]]++;
//         }
//         int index = 0; // now sort it out in the array
//         for(int i = minVal; i <= maxVal; i++){
//             while(freq[i] > 0){
//                 nums[index++] = i;
//                 freq[i]--;
//             }
//         }
//         // Sliding window on the sorted array
//         while(right < n){
//             windowSum += nums[right];

//             while((right - left + 1) * nums[right] > (windowSum + k)){
//                 windowSum -= nums[left];
//                 left++;
//             }
//             res = max(res, right - left + 1);
//             right++;
//         }
//         return (int)res;
//     }
// };

// struct FastIO{

//     FastIO(){
//         ios::sync_with_stdio(false);
//         cin.tie(nullptr);
//         cout.tie(nullptr);
//     }

// } obj;


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        const int MAX = 100000;
        vector<int> cnt(MAX + 1);

        for (int x : nums)
            cnt[x]++;

        int idx = 0;
        for (int val = 1; val <= MAX; val++) {
            while (cnt[val]--) {
                nums[idx++] = val;
            }
        }

        long long sum = 0;
        int ans = 1;
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            while (1LL * nums[r] * (r - l + 1) - sum > k) {
                sum -= nums[l++];
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
