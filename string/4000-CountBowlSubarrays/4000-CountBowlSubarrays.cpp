// Last updated: 19/08/2026, 15:21:48
class Solution {
    public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> lt(n,-1),rt(n,-1);
        stack<int> st;
        for(int i=0; i<n; ++i){
            while(!st.empty() && nums[st.top()] < nums[i]){
                rt[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1; i>=0; --i){
            while(!st.empty() && nums[st.top()] < nums[i]){
                lt[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        long long ans = 0;
        for(int i=0; i<n; ++i){
            int l = lt[i];
            int r = rt[i];
            if(l != -1 && r != n){
                if(r-l+1 >= 3)ans++;
            }
        }
        return ans;
    }
};
