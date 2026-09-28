// Last updated: 28/09/2026, 09:53:59
class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int a = 0,b= 0;
        int n = nums.size();
        map<pair<int,int>,int> mpp;
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1]){
                a++;
            }else{
                int x = nums[i-1];
                int y = nums[i];
                if(x>y)swap(x,y);
                mpp[{x,y}]++;
                b = max(b,mpp[{x,y}]);
            }
        }
        return a + b;
    }
};