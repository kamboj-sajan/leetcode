// Last updated: 25/09/2026, 01:12:13
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0;
        int r = arr.size() -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            int mis = arr[mid] - (mid+1);
            if(mis < k)l = mid+1;
            else r = mid-1;
        }
        return (r + 1 + k); 
    }
};