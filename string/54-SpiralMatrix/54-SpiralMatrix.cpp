// Last updated: 19/08/2026, 16:11:31

// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//        int n = matrix.size() ;
//        int m = matrix[0].size();
//        int left = 0 , right = m - 1;
//        int top = 0 , bottom = n -  1;
//        vector<int> ans;

//        while(top <= bottom && left <= right){
//         // right
//         for(int i=left; i<=right; i++){
//             ans.push_back(matrix[top][i]);
//         }
//         top++;
//         for(int i=top; i<=bottom; i++){
//             ans.push_back(matrix[i][right]);
//         }
//         right--;
//         if(top <= bottom){
//             for(int i = right; i>=left; i--){
//                 ans.push_back(matrix[bottom][i]);
//             }
//             bottom--;
//         }
//         if(left <= right){
//             for(int i = bottom; i>=top; i--){
//                 ans.push_back(matrix[i][left]);
//             }
//             left++;
//         }
//        }
//  return ans;
//     }
// };

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n= matrix[0].size(), m= matrix.size();
        
        int top=0,down=m-1,left=0,right=n-1, count=0;
        
        while(top<=down && left<=right){
            if(count==0){
                for(int i=left; i<=right; i++)
                    ans.push_back(matrix[top][i]);
                top++; count++;
            }
            else if(count==1){
                for(int i=top; i<=down; i++)
                    ans.push_back(matrix[i][right]);
                right--; count++;
            }
            else if(count==2){
                for(int i=right; i>=left; i--)
                    ans.push_back(matrix[down][i]);
                down--; count++;
            }
            else if(count==3){
                for(int i=down; i>=top; i--)
                    ans.push_back(matrix[i][left]);
                left++; count=0;
            }
        }
        
        return ans;
    }
};