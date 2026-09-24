// Last updated: 25/09/2026, 00:55:32
class Solution {
public:
    int minOperations(string s) {
        int mini = INT_MAX;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == 'a'){
                continue;
            }else{
                mini = min(mini,s[i]-'a');
            }
        }
        if(mini == INT_MAX)return 0;
        else{
            return (26-mini);
        }
    }
};