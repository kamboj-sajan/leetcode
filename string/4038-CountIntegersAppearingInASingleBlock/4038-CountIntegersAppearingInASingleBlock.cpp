// Last updated: 24/09/2026, 00:48:23
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<int> st;
        for(int i=0; i<n; i++){
            if(st.find(nums[i]) != st.end()){
                continue;
            }
            int j = i;
            while(j < n && nums[j] == nums[i]){
                j++;
            }
            st.insert(nums[i]);
            bool a = false;
            for(int k=j; k<n; k++){
                if(nums[k] == nums[i]){
                    a = true;
                    break;
                }
            }
            if(!a)ans++;
            i = j-1;
        }
        return ans;
    }
};