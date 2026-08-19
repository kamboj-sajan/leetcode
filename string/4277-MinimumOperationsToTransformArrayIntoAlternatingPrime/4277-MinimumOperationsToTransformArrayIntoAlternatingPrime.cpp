// Last updated: 19/08/2026, 15:15:59
class Solution {
public:
    vector<int> p;
    int maxi = 200009;
    void pr(){
        p.assign(200009,true);
        p[0] = false;
        p[1] = false;
        for(int i=2; i*i <maxi; ++i){
            for(int j=i*i; j<maxi ; j+=i){
                p[j] = false;
            }
        }
    }
public:
    int minOperations(vector<int>& nums) {
        pr();
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; ++i){
            int a = nums[i];
            if(i % 2 == 0){
                while(!p[a]){
                    a++;
                    cnt++;
                }
            }else{
                while(p[a]){
                    a++;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};