// Last updated: 11/10/2026, 08:09:42
// // class Solution {
// // public:
// //     vector<int> dailyTemperatures(vector<int>& temperature) {
// //         int n = temperature.size();
// //         vector<int> ans;
// //         for(int i=0; i<n; i++){
// //             int a = 0;
// //             bool b = false;
// //             for(int j=i+1; j<n; j++){
// //                 a++;
// //                 if(temperature[j] > temperature[i]){
// //                     ans.push_back(a);
// //                     b = true;
// //                     break;
// //                 }
// //             }
// //             if(!b)ans.push_back(0);
// //         }   
// //         return ans;
// //     }
// // };tle 

// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temp) {
//         int n = temp.size();
//         vector<int> ans(n);
//         stack<int> st;
//         for(int i=0; i<n; i++){
//             while(!st.empty() && temp[st.top()] < temp[i]){
//                 ans[st.top()] = i - st.top();
//                 st.pop();
//             }
//             st.push(i);
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         vector<int> answer;
//         answer.push_back(0);
//         for(int i= temperatures.size()-2; i>=0; i--){
//             if(temperatures[i]<temperatures[i+1]){
//                 answer.push_back(1);
//             } else if(temperatures[i] == temperatures[i+1]){
//                 int curAnswer = answer.back() +(bool)answer.back();
//                 answer.push_back(curAnswer);
//             }else{
//                 int cur = i+1;
//                 int answerIndex = answer.size()-1;
//                 int x = answer[answerIndex];
//                 while(x>0){
//                     //cout<<"i: "<<i<<", cur: "<<cur<<", answerIndex:"<<answerIndex<<", x:"<<x<<endl;
//                     if(temperatures[i] < temperatures[cur+x]){
//                         for(int j=cur; j<=cur+x; j++){
//                             if(temperatures[i] < temperatures[j]){
//                                 answer.push_back(j-i);
//                                 break;
//                             }
//                         }
//                         break;
//                     }else {
//                         cur +=x;
//                         answerIndex-=x;
//                         x = answer[answerIndex];
//                     }
//                 }

//                 if(x == 0){
//                     answer.push_back(0);
//                 }
//             }
//         }

//         reverse(answer.begin(), answer.end());
//         return answer;
//     }
// };

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && temp[st.top()] <= temp[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = 0;
            }else{
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};