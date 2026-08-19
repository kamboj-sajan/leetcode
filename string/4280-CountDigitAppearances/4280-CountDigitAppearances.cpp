// Last updated: 19/08/2026, 15:15:51
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