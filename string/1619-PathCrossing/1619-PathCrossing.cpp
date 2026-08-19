// Last updated: 19/08/2026, 15:47:14
// class Solution {
// public:
//     bool isPathCrossing(string path) {
//         int x = 0, y = 0;
//         set<pair<int,int>> visited;
//         visited.insert({0,0});
//         for(char c : path){
//             if(c == 'N') y++;
//             else if(c == 'S') y--;
//             else if(c == 'E') x++;
//             else x--;
//             if(visited.count({x,y})) return true;
//             visited.insert({x,y});
//         }
//         return false;
//     }
// };

// class Solution {
// public:
//     bool isPathCrossing(string path) {
//         int x = 0, y = 0;
//         unordered_set<string> visited;
//         visited.insert("0,0");
//         for(char c : path){
//             if(c == 'N') y++;
//             else if(c == 'S') y--;
//             else if(c == 'E') x++;
//             else x--;
//             string pos = to_string(x) + "," + to_string(y);
//             if(visited.count(pos)) return true;
//             visited.insert(pos);
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool isPathCrossing(string path) {

        set<pair<int,int>> st;

        st.insert({0,0});

        int x=0;
        int y=0;

        for(auto& it:path){
            if(it=='N') y++;
            else if(it=='S') y--;
            else if(it=='E') x++;
            else x--;

            if(st.count({x,y})) return true;

            st.insert({x,y});
        }
        return false;
    }
};