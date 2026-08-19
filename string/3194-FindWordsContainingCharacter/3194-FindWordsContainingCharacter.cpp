// Last updated: 19/08/2026, 15:29:37
class Solution {
public:
    bool f(string &word, char &x){
        for(int i=0; i<word.size(); ++i){
            if(word[i] == x){
                return true;
            }
        }
        return false;
    }
    vector<int> findWordsContaining(vector<string>& words, char x) {
       vector<int> ans;
       for(int i=0; i<words.size(); ++i){
        if(f(words[i],x))ans.push_back(i);
       } 
       return ans;
    }
};