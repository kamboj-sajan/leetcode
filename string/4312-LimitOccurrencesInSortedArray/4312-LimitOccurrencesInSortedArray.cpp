// Last updated: 19/08/2026, 15:15:45
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& arr, int k) {
       vector<int> ans;
        for(int i : arr){
            if(ans.size() < k || ans[ans.size() - k] != i){
                ans.push_back(i);
            }
        }
        return ans;
    }
};