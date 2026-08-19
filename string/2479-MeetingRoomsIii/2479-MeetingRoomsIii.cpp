// Last updated: 19/08/2026, 15:31:40
// class Solution {
// public:
//     typedef long long ll;

//     int mostBooked(int n, vector<vector<int>>& meetings) {
//         // Sort meetings by start time
//         sort(meetings.begin(), meetings.end());

//         // Min-heap of available room indices
//         priority_queue<int, vector<int>, greater<int>> available;
//         for (int i = 0; i < n; i++) {
//             available.push(i);
//         }

//         // Min-heap of busy rooms: {endTime, roomIndex}
//         priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> busy;

//         vector<int> count(n, 0);

//         for (auto &m : meetings) {
//             ll start = m[0];
//             ll end = m[1];
//             ll duration = end - start;

//             // Free rooms that have finished
//             while (!busy.empty() && busy.top().first <= start) {
//                 available.push(busy.top().second);
//                 busy.pop();
//             }

//             if (!available.empty()) {
//                 // Assign immediately
//                 int room = available.top();
//                 available.pop();
//                 busy.push({end, room});
//                 count[room]++;
//             } else {
//                 // Delay meeting
//                 auto [freeTime, room] = busy.top();
//                 busy.pop();
//                 busy.push({freeTime + duration, room});
//                 count[room]++;
//             }
//         }

//         // Find room with maximum meetings
//         int ans = 0;
//         for (int i = 1; i < n; i++) {
//             if (count[i] > count[ans]) {
//                 ans = i;
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
struct cmp
{
    bool operator()(const pair <long long, long long>& p1, const pair <long long, long long>& p2) const
    {
        if(p1.first != p2.first) return p1.first > p2.first;

        return p1.second > p2.second;
    }
};
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue <int, vector <int>, greater <int> > rooms;
        for(int i=0;i<n;i++) rooms.push(i);
        vector <int> res(n);
        priority_queue <pair <long long, int> , vector <pair <long long, int>>, greater <pair <long long, int>> > current;
        int ans = 0, maxm = 0;
        for(auto meeting: meetings)
        {
            while(!current.empty() && current.top().first <= meeting[0])
            {
                pair <long long, int> pp = current.top();
                current.pop();
                rooms.push(pp.second);
            }
            if(!rooms.empty())
            {
                current.push({meeting[1], rooms.top()});
                res[rooms.top()]++;
                rooms.pop();
            }
            else
            {
                pair <long long, int> pp = current.top();
                current.pop();
                res[pp.second]++;
                current.push({pp.first+(meeting[1]-meeting[0]),pp.second});
            }
        }

        for(int i=0;i<n;i++)
        {
            if(maxm < res[i])
            {
                maxm = res[i];
                ans = i;
            }
        }

        return ans;
    }
};