// Last updated: 25/09/2026, 00:59:43
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n);

        int rem = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0) result[i] = 0;
            if(nums[i] > 0){
                rem = nums[i] % n;
                if(rem + i >= n){
                    result[i] = nums[i+rem-n];
                }else{
                    result[i] = nums[i+rem];
                }
            }else{
                rem = abs(nums[i]) % n;
                if(rem > i){
                    result[i] = nums[n - rem + i];
                }else{
                    result[i] = nums[i - rem];
                }
            }
        }

        return result;
    }
};