// Last updated: 19/08/2026, 16:11:07
// class Solution {
// public:
//     string getPermutation(int n, int k) {
//         int fact = 1;
//         vector<int> numbers;
//         for(int i=1; i<n; i++){
//             fact = fact * i;
//             numbers.push_back(i);
//         }
//         numbers.push_back(n);
//         string ans = "";
//         k = k-1;
//         while(true){
//             ans = ans + to_string(numbers[k/fact]);
//             numbers.erase(numbers.begin() + k/fact);
//             if(numbers.size() == 0){
//                 break;
//             }
//             k = k%fact;
//             fact = fact/numbers.size();
//         }
//         return ans;
//     }
// };


class Solution {
public:
    string getPermutation(int n, int k) {
        // bruteforce getting all the permutations until k - worst
        // 1234; n = 4, k = 9
        vector<int> nums;
        int fact = 1;
        // 1,2,3
        for(int i = 1; i < n; i++) { 
            // fact = 6
            fact = fact * i;
            nums.push_back(i);
        }
        // nums = 1,2,3,4
        nums.push_back(n);

        // considering 0 indexing k = 8
        k--;
        string ans = "";
        while(true) {
            // index = 8/6 = 1 
            // index = 1, so choose nums[1] = 2
            int index = k / fact;
            // ans = 2 - - - 
            ans += to_string(nums[index]);
            // erasing that 2 from nums array
            nums.erase(nums.begin() + index);
            if(nums.size() == 0) break;

            // k = 8 % 6 = 2
            k = k % fact;
            // fact = 6/3 = 2;
            // Now fact = 2! because 3 numbers remain [1,3,4]
            fact = fact / nums.size();
        }
        return ans;
    }
};