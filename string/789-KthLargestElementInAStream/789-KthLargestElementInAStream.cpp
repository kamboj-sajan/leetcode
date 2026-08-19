// Last updated: 19/08/2026, 15:57:08
// class KthLargest {
//     int k;
//     priority_queue<int,vector<int>,greater<int>> pq;
// public:
//     KthLargest(int k, vector<int>& nums) {
//         int n = nums.size();
//         this -> k = k;
//         if(k > n){
//             for(int i=0; i<n; ++i){
//                 pq.push(nums[i]);
//             }
//         }else{
//         for(int i=0; i<k; ++i){
//             pq.push(nums[i]);
//         }
//         for(int i=k; i<n; ++i){
//             if(nums[i] > pq.top()){
//                 pq.pop();
//                 pq.push(nums[i]);
//             }
//         }
//         }
//     }
    
//     int add(int val) {
//         if(pq.size() < k){
//             pq.push(val);
//         }else{
//         if(val > pq.top()){
//             pq.pop();
//             pq.push(val);
//         }}
//         return pq.top();
//     }
// };

// /**
//  * Your KthLargest object will be instantiated and called as such:
//  * KthLargest* obj = new KthLargest(k, nums);
//  * int param_1 = obj->add(val);
//  */


class KthLargest {
    int k;  // store k
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop(); // keep only k largest elements
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop(); // maintain only k elements
        }
        return pq.top(); // kth largest
    }
};
