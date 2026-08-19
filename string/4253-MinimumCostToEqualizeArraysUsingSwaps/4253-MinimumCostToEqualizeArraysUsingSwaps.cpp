// Last updated: 19/08/2026, 15:16:51
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
       int n = nums1.size();
        unordered_map<int,int> mpp;
        
        for(int i = 0; i < n; ++i){
            mpp[nums1[i]]++;
            mpp[nums2[i]]++;
        }
        
        for(auto &p : mpp){
            if(p.second % 2 == 1) return -1;
        }
        
        unordered_map<int,int> frqnd;
        for(auto &p : mpp){
            frqnd[p.first] = p.second / 2; 
        }
        
        long long a = 0;
        unordered_map<int,int> fr1;
        for(int i = 0; i < n; ++i){
            fr1[nums1[i]]++;
        }
        
        for(auto &p : fr1){
            if(p.second > frqnd[p.first]){
                a += p.second - frqnd[p.first];
            }
        }
        return a;
    }
};