// Last updated: 24/09/2026, 00:49:51
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();
        int cnt = 0;
        char a = digit + '0';
        for(int i: nums){
            string str = to_string(i);
            for(char d : str){
            if(a == d)cnt++;
            }
        }
        return cnt;
    }
};