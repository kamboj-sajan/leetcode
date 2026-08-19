// Last updated: 19/08/2026, 15:33:29
// class Solution {
// public:
//     int maxDistance(vector<int>& colors) {
//         int maxi = INT_MIN;
//         int n = colors.size();
//         for(int i=n-1; i>=0; i--){
//            if(colors[i] != colors[0]){
//             maxi = max(maxi,i);
//            }
//         }
//         for(int i=0; i<n; i++){
//            if(colors[i] != colors[n-1]){
//             maxi = max(maxi,n-1-i);
//            }
//         }
//         return maxi;
//     }
// };

// class Solution {
// public:
//     int maxDistance(vector<int>& colors) {
//         int n = colors.size();
//         int ans = 0;
//         int i=0; int j=n-1;
//         while(colors[i]==colors[j]) j--;
//         ans = max(ans,j-i);

//         j = n-1;
//         while(colors[i]==colors[j]) i++;
//         ans = max(ans,j-i);

//         return ans;
//     }
// };

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            if(colors[i] != colors[0]) {
                maxi = max(maxi, i);  // distance from 0
            }
            if(colors[i] != colors[n-1]) {
                maxi = max(maxi, n - 1 - i);  // distance from end
            }
        }

        return maxi;
    }
};