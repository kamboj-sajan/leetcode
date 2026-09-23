// Last updated: 24/09/2026, 00:51:10
class Solution {
public:
    string trimTrailingVowels(string s) {
        unordered_set<char> mpp = {'a','e','i','o','u'};
        int j = -1;
        for(int i=s.size()-1; i>=0; --i){
            if(mpp.count(s[i]) == 0){
               j = i;
                break;
            }
        }
        return s.substr(0,j+1);
    }
};