// Last updated: 19/08/2026, 15:39:01
// class Solution {
// public:
//     bool f(vector<int> &arr,int mid,int m){
//         int cncw = 1;
//         int lcw = arr[0];
//         for(int i=1; i<arr.size(); i++){
//             if(arr[i]-lcw >= mid){
//                 cncw++;
//                 lcw = arr[i];
//             }
//         }
//         if(cncw >= m)return true;
//         else return false;
        
//     }
// public:
//     int maxDistance(vector<int>& position, int m) {
//         int l = 0;
//         int n = position.size();
//         sort(position.begin(),position.end());
//         int r = position[n-1] - position[0];
//         int ans = 1;
//         while(l <= r){
//             int mid = l + (r-l)/2;
//             if(f(position,mid,m)){
//                 ans = mid;
//                 l = mid+1;
//             }else{
//                 r = mid-1;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    bool canPlaceBalls(int x, vector<int>& position, int m) {
        // Place the first ball at the first position.
        int prevBallPos = position[0];
        int ballsPlaced = 1;

        // Iterate on each 'position' and place a ball there if we can place it.
        for (int i = 1; i < position.size() && ballsPlaced < m; ++i) {
            int currPos = position[i];
            // Check if we can place the ball at the current position.
            if (currPos - prevBallPos >= x) {
                ballsPlaced += 1;
                prevBallPos = currPos;
            }
        }
        return ballsPlaced == m;
    }

    int maxDistance(vector<int>& position, int m) {
        int answer = 0;
        int n = position.size();
        sort(position.begin(), position.end());

        // Initial search space.
        int low = 1;
        int high = ceil(position[n - 1] / (m - 1.0));
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlaceBalls(mid, position, m)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return answer;
    }
};