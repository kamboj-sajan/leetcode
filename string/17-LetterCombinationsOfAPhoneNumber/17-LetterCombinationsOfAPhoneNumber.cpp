// Last updated: 19/08/2026, 16:13:39
class Solution {
public:
    vector<string> ans;
    void f(int ind,string &temp,string &digits,map<char,string> &mapping){
        if(ind == digits.size()){
            ans.push_back(temp);
            return;
        }
        char ch = digits[ind];
        for(char letter:mapping[ch]){
            temp += letter;
            f(ind+1,temp,digits,mapping);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)return ans;
        map<char,string> mapping;
        mapping['2'] = {"abc"};
        mapping['3'] = {"def"};
        mapping['4'] = {"ghi"};
        mapping['5'] = {"jkl"};
        mapping['6'] = {"mno"};
        mapping['7'] = {"pqrs"};
        mapping['8'] = {"tuv"};
        mapping['9'] = {"wxyz"};
        string temp;
        f(0,temp,digits,mapping);
        return ans;
    }
};