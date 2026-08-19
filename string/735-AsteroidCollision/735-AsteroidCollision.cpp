// Last updated: 19/08/2026, 15:57:50
// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         int i = 0;
//         while (i < (int)asteroids.size() - 1) {
//             if (asteroids[i] > 0 && asteroids[i+1] < 0) {
//                 if (abs(asteroids[i]) > abs(asteroids[i+1])) {
//                     asteroids.erase(asteroids.begin() + i + 1);
//                 } else if (abs(asteroids[i]) < abs(asteroids[i+1])) {
//                     asteroids.erase(asteroids.begin() + i);
//                     if (i > 0) i--;  
//                 } else {
//                     asteroids.erase(asteroids.begin() + i, asteroids.begin() + i + 2);
//                     if (i > 0) i--; 
//                 }
//             } else {
//                 i++;
//             }
//         }
//         return asteroids;
//     }
// };

// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         int n = asteroids.size();
//         stack<int> st;
//         vector<int> ans;
//         for(int i=0; i<n; i++){
//             int cur = asteroids[i];
//             while(!st.empty() && cur < 0 && st.top() > 0){
//                 if(abs(cur) < st.top()){
//                     cur = 0;
//                     break;
//                 }else if(abs(cur) == st.top()){
//                     st.pop();
//                     cur = 0;
//                     break;
//                 }
//                 else{
//                     st.pop();
//                     continue;
//                 }
//             }
//             if(cur != 0)st.push(cur);
//         }
//        while(!st.empty()){
//         int el = st.top();
//         ans.push_back(el);
//         st.pop();
//        }
//        reverse(ans.begin(),ans.end());
//        return ans;
//     }
// };

// using vector

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n = asteroids.size();
        for(int i=0; i<n; i++){
            if(asteroids[i] > 0)ans.push_back(asteroids[i]);
            else{
            while(!ans.empty() && ans.back() > 0 && ans.back() < abs(asteroids[i])){
                ans.pop_back();
            }
            if(!ans.empty() && ans.back() == abs(asteroids[i])){
                ans.pop_back();
            }
            else if(ans.empty() || ans.back() < 0){
                ans.push_back(asteroids[i]);
            }
        }
            }
        return ans;
    }
};