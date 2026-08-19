// Last updated: 19/08/2026, 15:46:47
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