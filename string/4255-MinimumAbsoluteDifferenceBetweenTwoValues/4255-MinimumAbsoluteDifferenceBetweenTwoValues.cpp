// Last updated: 19/08/2026, 15:16:47
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int mini = INT_MAX;
        int a = -1;
        int b = -1;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] == 1){
                if(b != -1){
                    a = i;
                    mini = min(mini,abs(a - b));
                }
                a = i;
            }else if(nums[i] == 2){
                if(a != -1){
                    b = i;
                    mini = min(mini,abs(a - b));
                }else{
                    b = i;
                }
            }
        }
        if(mini == INT_MAX)return -1;
        else return mini;
    }
};