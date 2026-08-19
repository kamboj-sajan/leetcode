// Last updated: 19/08/2026, 16:13:59
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int n = height.size();
//         int l = 0;
//         int r = n-1;
//         int ans= -1;
//         using ll = long long;
//         while(l<=r){
//             ll a = 1LL*min(height[l],height[r])*(r-l);
//             ans = max(ans,(int)a);
//             if(height[l] < height[r])l++;
//             else r--;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maxArea(vector<int>& height) {
     int n = height.size();
     int left = 0;
     int right = n-1;
     int max_area = 0;
     while(left<right)
     {  int area = (right-left)*(min(height[left],height[right]));
        max_area = max(max_area,area);
        if(height[left]<height[right])
            left++;
        else
            right--;
     }
     return max_area;
    }
};