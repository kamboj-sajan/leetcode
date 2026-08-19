// Last updated: 19/08/2026, 15:23:19
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
       int n = nums.size();
        if(n<3)return false;
        int i =0;
        while(i+1<n && nums[i] < nums[i+1])i++;
        if(i == 0)return false;
        int p = i;
        while(i+1<n && nums[i] > nums[i+1])i++;
        if(i==p)return false;
        int q = i;
        while(i+1<n && nums[i] <nums[i+1])i++;
        if(i==q)return false;
        if(i== n-1)return true;
        else return false;
    }
};