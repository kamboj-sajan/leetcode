// Last updated: 19/08/2026, 16:00:55
// // class Solution {
// // public:
// // void merge(vector<int> &arr, int low, int mid, int high) {
// //     vector<int> temp; // temporary array
// //     int left = low;      // starting index of left half of arr
// //     int right = mid + 1;   // starting index of right half of arr

// //     //storing elements in the temporary array in a sorted manner//

// //     while (left <= mid && right <= high) {
// //         if (arr[left] <= arr[right]) {
// //             temp.push_back(arr[left]);
// //             left++;
// //         }
// //         else {
// //             temp.push_back(arr[right]);
// //             right++;
// //         }
// //     }

// //     // if elements on the left half are still left //

// //     while (left <= mid) {
// //         temp.push_back(arr[left]);
// //         left++;
// //     }

// //     //  if elements on the right half are still left //
// //     while (right <= high) {
// //         temp.push_back(arr[right]);
// //         right++;
// //     }

// //     // transfering all elements from temporary to arr //
// //     for (int i = low; i <= high; i++) {
// //         arr[i] = temp[i - low];
// //     }
// // }
// // public:
// // int countPairs(vector<int>& arr, int low, int mid, int high){
// //     int right = mid + 1;
// //     int cnt = 0;
// //     for(int i=low; i<=mid; i++){
// //         while(right <= high && arr[i] > 2LL * arr[right]) right++;
// //         cnt += (right - (mid + 1));
// //     }
// //     return cnt;
// // }
// // public:
// // int mergeSort(vector<int> &arr, int low, int high) {
// //     int cnt = 0;
// //     if (low >= high) return cnt;
// //     int mid = (low + high) / 2 ;
// //     cnt += mergeSort(arr, low, mid);  // left half
// //     cnt += mergeSort(arr, mid + 1, high); // right half
// //     cnt += countPairs(arr, low, mid, high);
// //     merge(arr, low, mid, high);  // merging sorted halves
// //     return cnt;
// // }
// // public:
// //     int reversePairs(vector<int>& nums) {
// //         int n = nums.size();
// //        return mergeSort(nums , 0 , n-1); 
// //     }
// // };

// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         return mergeSort(nums, 0, nums.size() - 1);
//     }

//     void merge(vector<int>& nums, int left, int mid, int right) {
//         vector<int> temp;
//         int i = left, j = mid + 1;

//         while (i <= mid && j <= right)
//         {
//             if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
//             else temp.push_back(nums[j++]);
//         }

//         while (i <= mid) temp.push_back(nums[i++]);
//         while (j <= right) temp.push_back(nums[j++]);

//         for (int k = 0; k < temp.size(); k++) {
//             nums[left + k] = temp[k];
//         }
//     }

//     long long mergeSort(vector<int>& nums, int left, int right) {
//         if (left >= right) return 0;

//         int mid = (left + right) / 2;
//         long long rev = 0;

//         rev += mergeSort(nums, left, mid);       // Left half
//         rev += mergeSort(nums, mid + 1, right);  // Right half
//         rev += countPairs(nums, left, mid, right);

//         merge(nums, left, mid, right);

//         return rev;
//     }

//     int countPairs(vector<int>& nums, int left, int mid, int right)
//     {
//         int cnt = 0;
//         int j = mid + 1;

//         for (int i = left; i <= mid; i++)
//         {
//             while(j <= right && (long long)nums[i] > 2LL * nums[j])
//             {
//                 cnt += mid - i + 1;
//                 j++;
//             }
//         }

//         return cnt;
//     }
// };

class Solution {
public:
    vector<int> seg;
    int m;

    void update(int idx, int l, int r, int pos) {
        if (l == r) {
            seg[idx]++;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2*idx, l, mid, pos);
        else update(2*idx+1, mid+1, r, pos);
        seg[idx] = seg[2*idx] + seg[2*idx+1];
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return seg[idx];
        int mid = (l + r) / 2;
        return query(2*idx, l, mid, ql, qr) + query(2*idx+1, mid+1, r, ql, qr);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<long long> vals;
        for (int x : nums) {
            vals.push_back(x);
            vals.push_back(2LL * x);
        }
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        auto getId = [&](long long x) {
            return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
        };

        m = vals.size();
        seg.assign(4 * (m + 2), 0);

        long long res = 0;
        for (int i = n - 1; i >= 0; i--) {
            int id = getId(nums[i]) - 1;
            res += query(1, 1, m, 1, id);
            update(1, 1, m, getId(2LL * nums[i]));
        }

        return (int)res;
    }
};