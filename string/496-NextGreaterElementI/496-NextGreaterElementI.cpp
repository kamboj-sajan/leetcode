// Last updated: 19/08/2026, 16:00:48
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
//         for(int i=0; i<nums1.size(); i++){
//             for(int j=0; j<nums2.size(); j++){
//                 if(nums1[i] == nums2[j]){
//                      int nextGreater = -1;
//                      for(int k=j+1; k<nums2.size(); k++){
//                             if(nums2[k] > nums2[j]){
//                                 nextGreater = nums2[k];
//                               break;
//                             }
//                         }
//                         ans.push_back(nextGreater);
//                         break;
//                     }
//                }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//          unordered_map<int, int> nge;
//         stack<int> st;
//         for(int i=nums2.size()-1; i>=0; i--){
//             while(!st.empty() && st.top() <= nums2[i]){
//                 st.pop();
//             }
//                 if(st.empty())nge[nums2[i]] = -1;
//                 else nge[nums2[i]] = st.top();
//                 st.push(nums2[i]);
//         }
//         vector<int> res;
//         for(int num : nums1){
//             res.push_back(nge[num]);
//         }
//         return res;;
//     }
// };

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//        vector<int> nge;
//        int ind = -1;
//        bool flag = false;
//        for(int i=0; i<nums1.size(); i++){
//         auto it = find(nums2.begin(),nums2.end(),nums1[i]);
//         if(it != nums2.end()){
//             ind = it - nums2.begin();
//         }
//         for(int j=ind; j<nums2.size(); j++){
//             if(nums1[i] < nums2[j]){
//                 nge.push_back(nums2[j]);
//                 flag = true;
//                 break;
//             }
//         }
//         if(flag == false)nge.push_back(-1);
//         flag = false;
//        }
//        return nge;
//     }
// };

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& v1, vector<int>& v2) {
    stack<int>s;
    unordered_map<int,int>m;
    int n=v2.size();
    s.push(v2[n-1]);
    m[v2[n-1]]=-1;
    for(int i=n-2;i>=0;i--){
       if(v2[i]<s.top()) m[v2[i]]=s.top();
       else{
        bool f=1;
        while(!s.empty()){
            if(v2[i]<s.top()){ 
            m[v2[i]]=s.top(); f=0;
            break;}
            s.pop();
        }
        if(f){
             m[v2[i]]=-1;
        }
       }
       s.push(v2[i]);
    }
    for(int i=0;i<v1.size();i++){
        v1[i]=m[v1[i]];
    }
    return v1;
    }
};