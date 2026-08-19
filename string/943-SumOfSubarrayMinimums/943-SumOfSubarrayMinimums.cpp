// Last updated: 19/08/2026, 15:55:32
// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         int n = arr.size();
//         int total = 0;
//         int mod = 1e9 + 7;
//     for(int i=0; i<n; i++){
//         int mini = INT_MAX;
//         for(int j=i; j<n; j++){
//                 mini = min(mini,arr[j]);
//                 total = (total + mini)%mod;
//         }
//     }
//     return total;
//     }
// };// tle 

class Solution {
public:
    vector<int> findNse(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPsee(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> psee(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i])st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
      int n = arr.size();
      int total = 0;
      int mod = (1e9 + 7);
      vector<int> nse = findNse(arr);
      vector<int> psee = findPsee(arr);
      for(int i=0; i<n; i++){
        int left = i - psee[i];
        int right = nse[i] - i;
        total = (total + (right * left * 1LL * arr[i]) % mod) % mod;
      }
      return total;
    }
};