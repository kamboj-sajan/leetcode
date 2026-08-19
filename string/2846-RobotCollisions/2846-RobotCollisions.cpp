// Last updated: 19/08/2026, 15:30:18
class Solution {
public:
   using ll = long long;

vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int n = positions.size();

    vector<tuple<int,int,char,int>> robots;
    for(int i = 0; i < n; i++) {
        robots.push_back({positions[i], healths[i], directions[i], i});
    }

    // Sort by position
    sort(robots.begin(), robots.end());

    stack<tuple<int,int,char,int>> st;

    for(auto &robot : robots) {
        auto [pos, health, dir, idx] = robot;

        if(dir == 'R') {
            st.push(robot);
        } else {
            // dir == 'L'
            bool alive = true;

            while(!st.empty()) {
                auto &[p2, h2, d2, i2] = st.top();

                if(d2 == 'L') break; // no collision

                // collision happens
                if(h2 < health) {
                    st.pop();
                    health--;
                }
                else if(h2 > health) {
                    h2--;
                    alive = false;
                    break;
                }
                else {
                    st.pop();
                    alive = false;
                    break;
                }
            }

            if(alive) {
                st.push({pos, health, dir, idx});
            }
        }
    }

    // Collect survivors
    vector<pair<int,int>> res;
    while(!st.empty()) {
        auto [p, h, d, i] = st.top();
        st.pop();
        res.push_back({i, h});
    }

    sort(res.begin(), res.end());

    vector<int> ans;
    for(auto &it : res) {
        ans.push_back(it.second);
    }

    return ans;
}
};