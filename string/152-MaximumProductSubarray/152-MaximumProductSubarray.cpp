// Last updated: 19/08/2026, 16:06:45
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int pre = 1 , suff = 1;
//         int ans = INT_MIN;
//         int n = nums.size();
//         for(int i = 0; i<n; i++){
//             if(pre == 0) pre = 1;
//             if(suff == 0) suff = 1;
//             pre = pre * nums[i];
//             suff = suff * nums[n-i-1];
//             ans = max(ans, max(pre,suff));
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = size(nums);
        if (n == 2) {
            return
            (nums[0] <=> 0 == nums[1] <=> 0) ? 
            nums[0] * nums[1] : 
            max(nums[0], nums[1]);
        }
        int min_ = nums[0], max_ = nums[0], ret = nums[0];
        int i = 1;
        while (i < n) {
            // possibilities
            int p1 = min_ * nums[i];
            int p2 = max_ * nums[i];
            int p3 = nums[i];

            min_ = min(p1, min(p2, p3));
            max_ = max(p1, max(p2, p3));

            ret = max(ret, max_);

            ++i;
            //cout << min_ << ", " << max_ << endl;
            if (min_ <= 0 && max_ >= 0) break;
        }
        while (i < n) {
            if (nums[i] == 0) {
                min_ = max_ = 0;
                //memset(&min_, 0, 8);
            } else if (nums[i] > 0) {
                int p1 = min_ * nums[i];
                int p2 = max_ * nums[i];
                int p3 = nums[i];

                min_ = p1;
                max_ = max(p2, p3);

                ret = max(ret, max_);
            } else {
                int p1 = min_ * nums[i];
                int p2 = max_ * nums[i];
                int p3 = nums[i];

                min_ = min(p2, p3);
                max_ = p1;

                ret = max(ret, max_);
            }
            //cout << min_ << ", " << max_ << endl;
            ++i;
        }
        return ret;
    }
};