// Last updated: 19/08/2026, 15:33:18
// class Solution {
// public:
//     long long subArrayRanges(vector<int>& nums) {
//         long long sum = 0;
//         int n = nums.size();
//         for(int i=0; i<n; i++){
//             int largest = nums[i];
//             int smallest = nums[i];
//             for(int j=i+1; j<n; j++){
//                 largest = max(largest,nums[j]);
//                 smallest = min(smallest,nums[j]);
//                 sum = sum + (largest-smallest);
//             }
//         }
//         return sum;
//     }
// }; brute force

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
    vector<int> findNge(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> nge(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int> findPgee(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> pgee(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] < arr[i])st.pop();
            pgee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pgee;
    }
public:
    long long sumMin(vector<int>& arr) {
      int n = arr.size();
      long long total = 0;
      vector<int> nse = findNse(arr);
      vector<int> psee = findPsee(arr);
      for(int i=0; i<n; i++){
        int left = i - psee[i];
        int right = nse[i] - i;
        total = (total + (right * left * 1LL * arr[i]));
      }
      return total;
    }
public:
    long long sumMax(vector<int> &arr){
        int n = arr.size();
      long long total = 0;
    
      vector<int> nge = findNge(arr);
      vector<int> pgee = findPgee(arr);
      for(int i=0; i<n; i++){
        int left = i - pgee[i];
        int right = nge[i] - i;
        total = (total + (right * left * 1LL * arr[i]));
      }
      return total;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumMax(nums) - sumMin(nums);
    }
};