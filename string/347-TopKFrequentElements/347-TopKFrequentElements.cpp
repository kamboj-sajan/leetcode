// Last updated: 19/08/2026, 16:02:45
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         priority_queue<pair<int,int>> pq;
//         unordered_map<int,int> mpp;
//         for(int &a : nums){
//             mpp[a]++;
//         }
//         for(auto &p : mpp){
//             pq.push({p.second,p.first});
//         }
//         vector<int> ans;
//         for(int i=k-1; i>=0; i--){
//             ans.push_back(pq.top().second);
//             pq.pop();
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         priority_queue<pair<int,int>> pq;
//         unordered_map<int,int> mpp;
//         for(int &a : nums){
//             mpp[a]++;
//         }
//         vector<pair<int,int>> vpp(mpp.begin(),mpp.end());
//         sort(vpp.begin(),vpp.end(),[](auto &a,auto &b){
//             return a.second > b.second;
//         });
//         vector<int> ans;
//         for(int i=0; i<k; ++i){
//             ans.push_back(vpp[i].first);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
   unordered_map<int, int> freqMap;
    
    // Count frequency of each element
    for (auto num : nums) {
        freqMap[num]++;
    }
    
    // Min-heap of pairs <frequency, element>
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    
    // Maintain heap of size k with top frequent elements
    for (auto entry : freqMap) {
        minHeap.push({entry.second, entry.first});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    vector<int> ans;
    
    // Extract elements from heap
    while (!minHeap.empty()) {
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }
    
    return ans; 
    }
};