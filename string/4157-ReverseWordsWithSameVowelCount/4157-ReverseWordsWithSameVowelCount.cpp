// Last updated: 19/08/2026, 15:18:45
class Solution {
public:
    bool vowel(char c){
        if(c == 'a' || c== 'e'|| c == 'i'|| c== 'o'|| c=='u'){
            return true;
        }else return false;
    }
    int cntvw(string &str){
        int cnt = 0;
        for(char c : str){
            if(vowel(c))cnt++;
        }
        return cnt;
    }
public:
    string reverseWords(string s) {
        vector<string> vec;
        string temp = "";
        for(char a : s){
            if(a == ' '){
                vec.push_back(temp);
                temp.clear();
            }else{
                temp.push_back(a);
            }
        }
        vec.push_back(temp);
        int fct = cntvw(vec[0]);
        for(int i=1; i<vec.size(); ++i){
            if(cntvw(vec[i]) == fct){
                reverse(vec[i].begin(),vec[i].end());
            }
        }
        string ans;
        for(int i=0; i<vec.size(); ++i){
            if(i)ans.push_back(' ');
            ans += vec[i];
        }
        return ans;
    }
};