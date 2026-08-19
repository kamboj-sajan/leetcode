// Last updated: 19/08/2026, 16:02:05
// class Solution {
//     string f(string s,int ind,int k){
//         if(ind == s.size()){
//             return s;
//         }
//         if(k == 0){
//             return s;
//         }
//         string notpick = f(s,ind+1,k);
//         string temp = s;
//         temp.erase(ind,1);
//         string pick = f(temp,ind,k-1);
//         return min(pick,notpick); 
//     }
// public:
//     string removeKdigits(string num, int k) {
//         string str = f(num,0,k);
//         int i = 0;
//         while(i < str.size() && str[i] == '0')i++;
//         str = str.substr(i);
//         return str.empty() ? "0" : str;
//     }
// }; tle 24/44

// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         stack<char> st;
//         for(int i=0; i<num.size(); i++){
//             while(!st.empty() && k>0 && (st.top() - '0') > (num[i] - '0')){
//                 st.pop();
//                 k = k-1;
//             }
//             st.push(num[i]);
//         }
//         while(k > 0 && !st.empty()){
//             st.pop(); 
//             k--;
//         }
//         if(st.empty())return "0";
//         string res = "";
//         while(!st.empty()){
//             res.push_back(st.top());
//             st.pop();
//         }
//         reverse(res.begin(),res.end());
//         int i = 0;
//         while (i < res.size() && res[i] == '0') i++;
//         res = res.substr(i);
//         if(res.empty()) return "0";
//         return res;
//     }
// };  striver

// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//          string st;
//         int n = num.length();
//         if(k == n) return "0";

//         for(int i=0; i<n; i++) {
            
//             //remove bigger digits
//             while( !st.empty() && k && st.back() > num[i] ) 
//             {
                
//                 st.pop_back();
//                 k--;
//             }

//             //put anything 0 or non zero if stack is not empty
//             //because it will not effect answer
//             if(!st.empty())
//             {
//                 st.push_back(num[i]);
//             } 
            
//             //stack is empty
//             else 
//             { 
//                 //if current digit is 0 we not take into stack
//                 //beacsue if stack is empty and if we push 0 
//                 //the answer will have trailing zero at first
                
//                 //only push non zero beacuse trailing zero not allowed
//                 if(num[i] != '0') {
//                     st.push_back(num[i]);
//                 }
//             }
//         }
        
//         //the remaining dgit removed from end to get smaller number
//         while(k && !st.empty()) {
//             st.pop_back();
//             k--;
//         }
        
//         return st.empty() ? "0" : st;
//     }
// };
/*
above code passing all cases but issues
❌ BUG in your code:
Case:
cpp
Copy
Edit
num = "10200", k = 1
Your code outputs: "200" ✅
But for:

cpp
Copy
Edit
num = "10", k = 1
It outputs: "1" ❌
Expected output is: "0"

Why?
Because your condition:

cpp
Copy
Edit
if (st.empty() && num[i] == '0') skip;
skips pushing '0' even when it's the only digit left.

pass all test cases why fix 
✅ So why fix it at all?
Because while it works on LeetCode's test cases, it’s still not clean logic. In corner cases or custom test cases (in interviews, or future versions), it might fail.
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for (char digit : num) {
            while (!st.empty() && k > 0 && st.back() > digit) {
                st.pop_back();
                k--;
            }
            st.push_back(digit);
        }

        while (k-- > 0 && !st.empty()) {
            st.pop_back();
        }

        int i = 0;
        while (i < st.size() && st[i] == '0') i++;
        string result = st.substr(i);

        return result.empty() ? "0" : result;
    }
};
