// Last updated: 19/08/2026, 15:36:37
class Solution {
public:
    vector<int> minOperations(string boxes) {
         int n = boxes.size();
        vector<int> ans(n);
        
        int leftBalls = 0, rightBalls = 0;
        int ops = 0;
        
        // Initial: count rightBalls and ops for index 0
        for (int i = 0; i < n; i++) {
            if (boxes[i] == '1') {
                rightBalls++;
                ops += i;
            }
        }
        
        // If box 0 has ball, adjust
        if (boxes[0] == '1') {
            leftBalls++;
            rightBalls--;
        }
        
        ans[0] = ops;
        
        // Traverse
        for (int i = 1; i < n; i++) {
            ops = ops + leftBalls - rightBalls;
            ans[i] = ops;
            
            if (boxes[i] == '1') {
                leftBalls++;
                rightBalls--;
            }
        }
        
        return ans;
    }
};