// Last updated: 19/08/2026, 15:16:36
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int b = *min_element(nums1.begin(),nums1.end());
        if(b % 2 != 0)return true;
        for(int i : nums1){
            if(i % 2 != 0)return false;
        }
        return true;
    }
};