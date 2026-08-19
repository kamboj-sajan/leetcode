// Last updated: 19/08/2026, 15:19:59
class Solution {
public:
    bool palr(int n){
        if(n == 0)return true;
        string s;
        while(n > 0){
            s.push_back('0' + (n&1));
            n >>= 1;
        }
        int i =0; 
        int j = s.size()-1;
        while(i < j){
            if(s[i] != s[j])return false;
            i++; 
            j--;
        }
        return true;
    }
public:
    vector<int> minOperations(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int> paln;
        for(int i=0; i<=2*maxi; ++i){
            if(palr(i))paln.push_back(i);
        }
        vector<int> ans;
        for(int p : nums){
            auto a = lower_bound(paln.begin(),paln.end(),p);
            int b = INT_MAX;
            if(a != paln.end())b = min(b,abs(p - *a));
            if(a != paln.begin()){
                a--;
                b = min(b,abs(p - *a));
            }
            ans.push_back(b);
        }
        return ans;
    }
};