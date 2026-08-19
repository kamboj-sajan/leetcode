// Last updated: 19/08/2026, 15:23:33
// class Solution {
// public:
//     vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
//         int n = code.size();
//         vector<string> ans;
//         unordered_map<string,int> mpp = {
//             {"electronics", 0},
//             {"grocery",1},
//             {"pharmacy",2},
//             {"restaurant",3}
//         };
//         vector<pair<int,string>> vld;
//         for(int i=0; i<n; ++i){
//             if(!isActive[i])continue;
//             if(mpp.find(businessLine[i]) == mpp.end())continue;
//             if(code[i].empty())continue;
//             bool a = true;
//             for(char c : code[i]){
//                 if(!(isalnum(c) || c == '_')){
//                     a = false;
//                     break;
//                 }
//             }
//             if(!a)continue;
//             vld.push_back({mpp[businessLine[i]],code[i]});
//         }
//         sort(vld.begin(),vld.end(), [] (auto &b, auto &c){
//             if(b.first != c.first)return b.first < c.first;
//             return b.second < c.second;
//         });
//         for(auto &d : vld){
//             ans.push_back(d.second);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
       int n = code.size();
       vector<string> ans;
       vector<string> cate = {"electronics", "grocery", "pharmacy", "restaurant"};
       unordered_map<string,vector<string>> mpp;
       for(int i=0; i<n; ++i){
           if(!isActive[i])continue;
           if(businessLine[i] != cate[0] && businessLine[i] != cate[1] && businessLine[i] != cate[2] && businessLine[i] != cate[3])continue;
           int f = 1;
           if(code[i].size() == 0)continue;
           for(int j=0; j<code[i].size(); j++){
            if(!((code[i][j] == '_') || (code[i][j]-'a' < 26 && code[i][j]-'a' >=0) || (code[i][j]-'A' < 26 && code[i][j]-'A' >=0) || (code[i][j]-'0' <=9 && code[i][j]-'0' >=0))){
                f =- 1;
                break;
            }
           }
           if(f == -1)continue;
           mpp[businessLine[i]].push_back(code[i]);
       }
       for(int i=0; i<4; ++i){
        auto it = mpp.find(cate[i]);
        if(it == mpp.end())continue;
        sort(it->second.begin(),it->second.end());
        for(int j=0; j<it->second.size(); ++j){
            ans.push_back(it->second[j]);
        }
       }
       return ans;
    }
};

