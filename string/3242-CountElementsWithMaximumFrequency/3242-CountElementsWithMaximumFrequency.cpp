// Last updated: 19/08/2026, 15:28:57
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
         unordered_map<int,int> freq; 
        for (int n : nums) {
            freq[n]++;
        }  
        int maxFreq = 0;
        for (auto &p : freq) {
            maxFreq = max(maxFreq, p.second);
        }
        int sum = 0;
        for (auto &p : freq) {
            if (p.second == maxFreq) {
                sum += p.second;
            }
        }
        return sum;
    }
};