// Last updated: 28/09/2026, 09:56:32
class Solution {
public: 
    bool f(vector<int> &vec,int n){
        for(int i=1; i<n; i++){
            int j = n-i;
            if(vec[i] == 0 || vec[j] == 0)continue;
            if(i != j || vec[i] >= 2){
                return true;
            }
        }
        for(int i=1; i+n<= 500; i++){
            if(vec[i] && vec[i+n])return true;
        }
        return false;
    }
public:
    int maxSubarray(vector<int>& nums) {
        vector<int> vec(501,0);
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j < n){
            int a = nums[j];
            while(f(vec,a)){
                vec[nums[i]]--;
                i++;
            }
            vec[a]++;
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};