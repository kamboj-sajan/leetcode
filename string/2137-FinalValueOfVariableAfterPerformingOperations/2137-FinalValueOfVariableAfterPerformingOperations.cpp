// Last updated: 19/08/2026, 15:34:09
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = 0;
        for(int i=0; i<operations.size(); ++i){
            if(operations[i] == "X++" || operations[i] == "++X")n++;
            else n--;
        }
        return n;
    }
};