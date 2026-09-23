// Last updated: 24/09/2026, 00:49:41
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