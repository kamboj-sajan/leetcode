// Last updated: 19/08/2026, 15:55:48
// class Solution {
// public:
//     int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
//         // Encode obstacles as string "x#y"
//         unordered_set<string> st;
//         for(auto &o : obstacles){
//             st.insert(to_string(o[0]) + "#" + to_string(o[1]));
//         }
//         // directions: N, E, S, W
//         vector<pair<int,int>> dir = {
//             {0,1}, {1,0}, {0,-1}, {-1,0}
//         };
//         int x = 0, y = 0;
//         int d = 0; // start facing North
//         int maxDist = 0;
//         for(int cmd : commands){
//             if(cmd == -1){
//                 d = (d + 1) % 4; // right
//             }
//             else if(cmd == -2){
//                 d = (d + 3) % 4; // left
//             }
//             else{
//                 for(int step = 0; step < cmd; step++){
//                     int nx = x + dir[d].first;
//                     int ny = y + dir[d].second;
//                     if(st.count(to_string(nx) + "#" + to_string(ny))){
//                         break; // obstacle hit
//                     }
//                     x = nx;
//                     y = ny;
//                     maxDist = max(maxDist, x*x + y*y);
//                 }
//             }
//         }
//         return maxDist;
//     }
// };

class Solution {
public:
    struct hash_pair {
        size_t operator()(const pair<int,int>& p) const {
            return hash<long long>()(((long long)p.first << 32) ^ p.second);
        }
    };

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int,int>, hash_pair> st;
        for(int i = 0; i < obstacles.size(); ++i){
            st.insert({obstacles[i][0], obstacles[i][1]});
        }
        int x = 0, y = 0;
        int d = 0; // 0=N, 90=E, 180=S, 270=W
        int ans = 0;

        for(int i = 0; i < commands.size(); ++i){

            if(commands[i] == -2){
                d = (d + 270) % 360; // left
            }
            else if(commands[i] == -1){
                d = (d + 90) % 360; // right
            }
            else{
                for(int step = 0; step < commands[i]; step++){
                    int nx = x, ny = y;
                    if(d == 0) ny++;
                    else if(d == 90) nx++;
                    else if(d == 180) ny--;
                    else nx--;
                    if(st.find({nx, ny}) != st.end()) break;
                    x = nx;
                    y = ny;
                    ans = max(ans, x*x + y*y);
                }
            }
        }

        return ans;
    }
};