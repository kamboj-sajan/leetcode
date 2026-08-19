// Last updated: 19/08/2026, 16:11:26
class Solution {
public:
    bool canJump(vector<int>& nums) {
      int n = nums.size();
      int maxind = 0;
      for(int i=0; i<n; i++){
        if(i > maxind)return false;
        maxind = max(maxind,i + nums[i]);
      }  
      return true;
    }
};