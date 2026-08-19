// Last updated: 19/08/2026, 16:10:07
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
        // int n = heights.size();
        // int maxi = INT_MIN;
        // for(int i=0; i<n-1; i++){
        //     if(heights[i] < heights[i+1]){
        //         int size = heights[i] * 2;
        //         maxi = max(maxi,size);
        //     }
        // }
//         return maxi;
//     }
// };  7/99 test cases

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int maxi = INT_MIN;
//         for(int i=0; i<n-1; i++){
//             if(heights[i] <= heights[i+1]){
//                 int size = heights[i] * 2;
//                 maxi = max(maxi,size);
//             }
//         }
//         return maxi;
//     }
// }; 12/99


// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//     int n = heights.size();
//     vector<int> lsmall(n,-1);
//     vector<int> rsmall(n,-1);
//     stack<int> st;
//     for(int i=0; i<n; i++){
//         while(!st.empty() && heights[st.top()] >= heights[i]){
//             st.pop();
//         }
//         if(st.empty())lsmall[i] = 0;
//         else lsmall[i] = st.top() + 1;
//         st.push(i);
//     }
//     while(!st.empty())st.pop();
//     for(int i=n-1; i>=0; i--){
//         while(!st.empty() && heights[st.top()] >= heights[i]){
//             st.pop();
//         }
//         if(st.empty())rsmall[i] = n-1;
//         else rsmall[i] = st.top() - 1;

//         st.push(i);
//     }
//     int maxi = INT_MIN;
//     for(int i=0; i<n; i++){
//         maxi = max(maxi,heights[i] * (rsmall[i] - lsmall[i] + 1));
//         // write this upper line in line number 54 to avoid one iteration
//     }
//     return maxi;
//     }
// };

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int maxa = 0;
    for(int i=0; i<=n; i++){
        while(!st.empty() && (i==n || heights[st.top()] >= heights[i])){
            int height = heights[st.top()];
            st.pop();
            int width;
            if(st.empty())width = i;
            else width = i - st.top() - 1;
            maxa = max(maxa,width * height);
        }
        st.push(i);
    }
    return maxa;
    }
};