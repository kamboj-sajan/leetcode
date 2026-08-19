// Last updated: 19/08/2026, 16:10:02
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m,0);
        int maxArea = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }else height[j] = 0;
            }
            int area = largestRectangleArea(height);
            maxArea = max(area,maxArea);
        }
        return maxArea;
    }
};