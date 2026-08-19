// Last updated: 19/08/2026, 15:27:07
// class Solution {
// public: 
//     vector<int> ans;
//     void f(int l,int r,vector<int> &nums,int x){
//         unordered_map<int,int> mpp;
//         for(int i=l; i<=r; ++i){
//             mpp[nums[i]]++;
//         }
//         priority_queue<pair<int,int>> pq;
//         for(auto &p : mpp){
//             pq.push({p.second,p.first});
//         }
//         int a = 0;
//         while(!pq.empty() && x !=0){
//             auto b = pq.top();
//             a += (b.first*b.second);
//             pq.pop();
//             x--;
//         }
//         ans.push_back(a);
//         return;
//     }
// public:
//     vector<int> findXSum(vector<int>& nums, int k, int x) {
//         int n = nums.size();
//         for(int i=0; i<n; ++i){
//             if(i+k-1 >= n)break;
//             f(i,i+k-1,nums,x);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> freq(51, 0 );
        vector<int> ans( n-k+1, 0 );
        //different treatment for first subarray
        for( int i = 0;i<k;i++)
            freq[nums[i]]++;
        priority_queue<pair<int,int>> pq;
        for(int i = 0;i<=50;i++)
        {
            if( freq[i] > 0 )
                pq.push( pair<int,int>(freq[i], i ) );
        }
        pair<int,int> tmp;
        int sm = 0;
        for( int i = 0 ;i<x && pq.size();i++)
        {
            tmp = pq.top();
            pq.pop();
            sm += tmp.first*tmp.second;
        }
        ans[0] = sm;
        //second subarray onwards
        for( int i = 1; i<n-k+1;i++)
        {
            freq[nums[i-1]]--;
            freq[nums[k+i-1]]++;
            priority_queue<pair<int,int>> pqn;
            for(int i = 0;i<=50;i++)
            {
                if( freq[i] > 0 )
                    pqn.push( pair<int,int>(freq[i], i ) );
            }
            pair<int,int> tmp;
            int sm = 0;
            for( int i = 0 ;i<x && pqn.size();i++)
            {
                tmp = pqn.top();
                pqn.pop();
                sm += tmp.first*tmp.second;
            }
            ans[i] = sm;           
        }
        return ans;
    }
};