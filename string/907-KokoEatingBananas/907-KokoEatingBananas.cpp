// Last updated: 19/08/2026, 15:55:44
class Solution {
public:
    bool f(vector<int> &piles,int mid,int h){
        int a = 0;
        for(int i : piles){
            a += ((i+mid-1)/mid);
            if(a > h)return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int r) {
        int a = *max_element(piles.begin(),piles.end());
        int l = 1;
        int h = a;
        int ans = 1;
        while(l <= h){
            int mid= l + (h-l)/2;
            if(f(piles,mid,r)){
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};