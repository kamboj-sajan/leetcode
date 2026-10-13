// Last updated: 13/10/2026, 10:47:19
class Solution {
public:
    bool threeFibonacciSum(int n) {
       if(n <= 1)return false;
        vector<int> vec;
        vec.push_back(0);
        vec.push_back(1);
        vec.push_back(1);
        while(vec.back() <= n){
            int a = vec.size();
            int sum = vec[a-1] + vec[a-2] + vec[a-3];
            if(sum == n)return true;
            int b = vec[a-1] + vec[a-2];
            if(b > n)break;
            vec.push_back(b);
        }
        return false;
    }
};