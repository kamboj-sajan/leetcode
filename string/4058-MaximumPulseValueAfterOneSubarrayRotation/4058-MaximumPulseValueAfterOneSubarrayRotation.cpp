// Last updated: 24/09/2026, 00:51:33
class Solution {
public:
    using ll = long long;
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        ll org = 0;
        ll a= 0;
        ll minie = 0;
        ll minio = 1e18;
        ll maxe = 0;
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                org += nums[i];
            }else org -= nums[i];
            ll b;
            if(i%2 == 0)b = -nums[i];
            else b = +nums[i];
            a += b;
            if((i+1)%2 == 0){
                if(a - minie > maxe){
                    maxe = a - minie;
                }
                if(a < minie){
                    minie = a;
                }
            }
            else{
                if(a - minio > maxe){
                    maxe = a - minio;
                }
                if(a < minio){
                    minio = a;
                }
            }
        }
        return org + 2 *maxe;
    }
};