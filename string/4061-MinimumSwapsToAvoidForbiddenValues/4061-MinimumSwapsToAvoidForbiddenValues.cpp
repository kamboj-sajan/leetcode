// Last updated: 19/08/2026, 15:20:34
class Solution {
public:
    bool f(vector<int> &nums,vector<int> &forbidden){
        bool a = true;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] == forbidden[i]){
                a = false;
                break;
            }
        }
        if(a == true)return true;
        else return false;
    }
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n = nums.size();
        if(f(nums,forbidden))return 0;
        unordered_map<int,int> cnt1,cnt2,bcnt;
        vector<int> vec;
        for(int i=0; i<n; ++i){
            cnt1[nums[i]]++;
            cnt2[forbidden[i]]++;
            if(nums[i] == forbidden[i]){
                vec.push_back(i);
                bcnt[nums[i]]++;
            }
        }
        for(auto &p : cnt1){
            int a = p.first;
            int b = p.second;
            int c = cnt2[a];
            if(b > n - c)return -1;
        }
        int d = vec.size();
        int maxi = 0;
        for(auto &it : bcnt){
            maxi = max(maxi,it.second);
        }
        int e = max((d+1)/2,maxi);
        return e;
    }
    
};