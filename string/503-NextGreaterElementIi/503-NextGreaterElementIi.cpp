// Last updated: 19/08/2026, 16:00:41
// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//        stack<int> st1;
//        stack<int> st2;
//        int n = nums.size();
//        unordered_map<int,int> nge1;
//         unordered_map<int,int> nge2;
    //     int j = 0;
    //    for(int i=n-1; i>=0; i++){
    //     j = n-1-i;
    //     while(!st1.empty() && st1.top() <= nums[i] ){
    //         st1.pop();
    //     }
    //     while(!st2.empty() && st2.top() <= nums[j]){
    //         st2.pop();
    //     }
    //       if(st1.empty()) nge1[i] = -1;   
    //     else nge1[i] = st1.top();

    //     st1.push(nums[i]);

    //     if(st2.empty()) nge2[j] = -1;   
    //     else nge2[j] = st2.top();

    //     st2.push(nums[j]);
    //    } 
    //    vector<int> res;
    //      for(int idx = 0; idx < n; idx++){
    //     int a = max(nge1[idx], nge2[idx]);  
    //     res.push_back(a);
    //    }
    //    return res;
//     }
// };
/* wrong intuition exm = {3,1,2}
rto l = 2 for 1;
ltor = 3
max = 3 but wrong answer;
*/


// class Solution {
// public:
//  vector<int> nextGreaterElements(vector<int>& nums) {
//    int n = nums.size();
//         vector<int> nge(n, -1); 

//         for(int i=0; i<n; i++){
//             for(int j=1; j<n; j++){
//                 int idx = (i + j) % n;  
//                 if(nums[idx] > nums[i]){
//                     nge[i] = nums[idx];
//                     break;
//                 }
//             }
//         }

//         return nge;
//     }
// };

// class Solution {
// public:
//  vector<int> nextGreaterElements(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> nge(n);
//     stack<int> st;
//     for(int i=2*n - 1; i>=0; i--){
//         while(!st.empty() && st.top() <= nums[i%n]){
//             st.pop();
//         }
//         if(i<n){
//             // nge[i] = st.empty() ? -1 : st.top();
//             if(st.empty()){
//                     nge[i] = -1;
//                 }
//                 else{
//                     nge[i] = st.top();
//                 }
//         }
//         st.push(nums[i%n]);
//     }
//     return nge;
//     }
// };

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> s;
        int maxidx=0;
        for (int i=0;i<n;i++)
        {
            if (nums[i]>nums[maxidx])
            {
                maxidx=i;
            }
        }
        int p;
        if (maxidx==0)
        {
            p=n-1;
        }
        else
        {
            p=maxidx-1;
        }
        s.push(nums[maxidx]);
        while(p!=maxidx)
        {
            while(!s.empty() && s.top()<=nums[p])
            {
                s.pop();
            }
            if (!s.empty())
            {
                ans[p]=s.top();
            }
            s.push(nums[p]);
            p--;
            if (p==-1)
            {
                p=n-1;
            }
        }
        return ans;
    }
};