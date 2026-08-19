// Last updated: 19/08/2026, 15:35:59
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
    int maxDist = 0;

    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] <= nums2[j]) {
            maxDist = max(maxDist, j - i);
            j++;  // try to expand distance
        } else {
            i++;  // move i to satisfy condition
        }
    }

    return maxDist;
    }
};