// Last updated: 19/08/2026, 15:15:30
class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int e = 0;
        int o = 0;
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            e = 0;
            o = 0;
            for(int j=i; j<n; j++){
                if(nums[j]%2 == 0)e++;
                else o++;
                if(o > 0){
                    if(1LL*e*b <= 1LL*a*o){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};