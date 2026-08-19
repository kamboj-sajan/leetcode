// Last updated: 19/08/2026, 16:06:00
// class Solution {
// public:
//     string largestNumber(vector<int>& nums) {
//         vector<string> vec;
//         int n = nums.size();
//         for(int i=0; i<n; ++i){
//             vec.push_back(to_string(nums[i]));
//         }
//         sort(vec.begin(),vec.end(),[](string &a,string &b){
//             return a+b > b+a;
//         });
//         if(vec[0] == "0")return "0";
//         string b;
//         for(int i=0; i<n; ++i){
//             b += vec[i];
//         }
//         return b;
//     }
// };

// class Solution {
// public:
//     string largestNumber(vector<int>& nums) {
//         vector<string> arr;
//         for (int num : nums)
//             arr.push_back(to_string(num));

//         sort(arr.begin(), arr.end(), [](string &a, string &b) {
//             return a + b > b + a; 
//         });

//         if (arr[0] == "0") return "0";

//         string ans;
//         for (string &s : arr) ans += s;

//         return ans;
//     }
// };

class Solution {
public:
static bool compare(string &a , string &b){
    return a+b > b+a;
};
    string largestNumber(vector<int>& nums) {
        vector<string> ans;

        for( int i : nums){
            ans.push_back(to_string(i));
        }

        string result = "";

        sort(ans.begin() , ans.end() , compare);
       if(ans[0] == "0") return "0";

       for( auto i :ans ){
        result += i;
       }
return result;
    }
};