// Last updated: 19/08/2026, 15:47:52
// class Solution {
// public:
//     string destCity(vector<vector<string>>& paths) {
//         unordered_map<string,int> mpp;
//         for(int i=0; i<paths.size(); ++i){
//             mpp[paths[i][0]]++;
//             mpp[paths[i][1]]--;
//         }
//         for(auto &p: mpp){
//             if(p.second == -1)return p.first;
//         }
//         return "";
//     }
// };

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string>st;
        for(auto &path : paths){
            string source = path[0];
            st.insert(source);
        }
        for(auto &path : paths){
             string dest = path[1];

             if( st.find(dest) == st.end()){
                return dest;
             }
        }
        return "not exists";
    }
};