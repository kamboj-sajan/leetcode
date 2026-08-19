// Last updated: 19/08/2026, 15:54:00
// // class Solution {
// // public:
// //     bool f(int cp,vector<int> &vec,int days){
// //         int a = 0;
// //         int d = 0;
// //         for(int i : vec){
// //             if(i > cp)return false;
// //             if(i + a > cp){
// //                 a = i;
// //                 d++;
// //             }else{
// //                 a += i;
// //             }
// //         }
// //         d += 1;
// //         if(d <= days)return true;
// //         else return false;
// //     }
// // public:
// //     int shipWithinDays(vector<int>& weights, int days) {
// //         int l = -1;
// //         int r = 0;
// //         for(int i : weights){
// //             r += i;
// //             l = max(i,l);
// //         }
// //         int ans = r;
// //         while(l <= r){
// //             int mid = l + (r-l)/2;
// //             if(f(mid,weights,days)){
// //                 ans = mid;
// //                 r = mid-1;
// //             }else{
// //                 l = mid+1;
// //             }
// //         }
// //         return ans;
// //     }
// // };

// class Solution {
// public:
//     bool canShip(vector<int>& weights, int mid, int days) {
//         int curr = 0;
//         int day = 1;

//         for (int weight : weights) {
//             if (curr + weight <= mid) {
//                 curr += weight;
//             } else {
//                 day++;
//                 curr = weight;
//             }
//         }

//         return day <= days;
//     }

//     int shipWithinDays(vector<int>& weights, int days) {
//         int low = *max_element(weights.begin(), weights.end());
//         int high = accumulate(weights.begin(), weights.end(), 0);

//         while (low <= high) {
//             int mid = low + (high - low) / 2;

//             if (canShip(weights, mid, days)) {
//                 high = mid - 1;
//             } else {
//                 low = mid + 1;
//             }
//         }

//         return low;
//     }
// };

// class Solution {
// public:
//     int findDays(vector<int>& weights , int cap){
//         int days = 1 , load = 0;
//         for(int i = 0; i<weights.size(); i++){
//             if(weights[i] + load > cap){
//                 days += 1;
//                 load = weights[i];
//             }else{
//                 load += weights[i];
//             }
//         }
//         return days;
//     }    
// public:
//     int shipWithinDays(vector<int>& weights, int days) {
//         int low = *max_element(weights.begin(), weights.end());
//         int high = accumulate(weights.begin(), weights.end(), 0);
//         while(low <= high){
//             int mid = (low + high)/2;
//             int numberofdays = findDays(weights , mid);
//             if(numberofdays <= days){
//                 high = mid - 1;
//             }else{
//                 low = mid + 1;
//             }
//         }
//         return low;
//     }
// };

class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity){
        int dayCount = 1;
        int currLoad = 0;
        for(int w:weights){
            // when exceeds capacity currLoad resets and shifted to next day
            if((currLoad+w)>capacity){
                dayCount++;
                currLoad = 0;
            }
            currLoad+=w;
        }
        return dayCount <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
      int low = *max_element(weights.begin(),weights.end());
      int high = accumulate(weights.begin(),weights.end(),0);
      int result = high; 

      while(low<=high){
        int mid = low+(high-low)/2;
        if(canShip(weights,days,mid)){
            result = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
      }
       return result;
    }
};