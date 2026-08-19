// Last updated: 19/08/2026, 15:56:50
// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<vector<pair<int,int>>> adj(n);
//         for (auto &p : flights) {
//             adj[p[0]].push_back({p[1], p[2]});
//         }

//         vector<int> dist(n, 1e9);
//         dist[src] = 0;

//         // queue: {stops, node, cost}
//         queue<pair<int, pair<int,int>>> q;
//         q.push({0, {src, 0}});

//         while (!q.empty()) {
//             auto cur = q.front();
//             q.pop();

//             int stops = cur.first;
//             int node  = cur.second.first;
//             int cost  = cur.second.second;

//             if (stops > k) continue;

//             for (auto &edge : adj[node]) {
//                 int nextNode = edge.first;
//                 int price = edge.second;

//                 if (cost + price < dist[nextNode]) {
//                     dist[nextNode] = cost + price;
//                     q.push({stops + 1, {nextNode, dist[nextNode]}});
//                 }
//             }
//         }

//         return dist[dst] == 1e9 ? -1 : dist[dst];
//     }
// };



// // Standard BellMan Ford algorithm, we can learn the algo from this standard question
// // original bellman:


// /* Initialize dist[src] = 0, all other dist to infinity.
// Loop V-1 times.
// In each iteration, relax EVERY edge [u, v, w]:
// Generated cpp
// // Standard Bellman-Ford Relaxation
// for (const auto& edge : all_edges) {
//     int u = edge.u;
//     int v = edge.v;
//     int w = edge.w;
//     // IMPORTANT: Reads and writes from the SAME `dist` array
//     if (dist[u] != infinity && dist[u] + w < dist[v]) {
//         dist[v] = dist[u] + w;
//     }
// }
// C++
// After V-1 loops, dist[dst] holds the shortest path cost. A V-th loop can be run to detect negative cycles.
// The key property of the standard implementation: When we update dist[v] in an iteration, that new, shorter distance to v can immediately be used to update v's neighbors within the same iteration.
// Example: In iteration 1, we find a path src -> A. Then, still in iteration 1, we process an edge A -> B. We can immediately use the new dist[A] to find a path src -> A -> B. So, in a single iteration, we can find paths of length > 1.*/


// // why not dijkstra, we can with modification of State in Priority Queue: {cost, currentNode, stopsMade}
// // which is complex, bellman is preferred 
// //  VERY IMPORTANT 
// /*Crucial: We only read from the original prices array and only write to temp_prices. This ensures that all paths calculated in one iteration use exactly one more edge than the paths from the previous iteration. It's like taking a snapshot.*/

// /*How it works
// Intuition
// Let dist[i] be the minimum cost to reach node i.
// After 0 flights, only dist[src] is 0, others are infinity.
// After 1 flight, we can update the distances to all neighbors of src.
// After 2 flights, we can update the distances to their neighbors, and so on.
// This maps directly to the K stops constraint. We can run the Bellman-Ford relaxation process K+1 times (for K+1 edges).
// Logic
// Initialize Distances: Create a prices array of size n, initialized to infinity. Set prices[src] = 0.
// Outer Loop: Loop K+1 times (from i = 0 to K). Each i represents being allowed to take i+1 flights.
// Inner Loop & The "Snapshot" Trick:
// Inside the loop, create a temporary copy of the prices array: temp_prices = prices.
// Iterate through every single flight [u, v, price] in the original flights list.
// If prices[u] is not infinity (meaning u was reachable in the previous iteration), we can potentially update the cost to v.
// The new cost to v would be prices[u] + price.
// Update the temporary array: temp_prices[v] = min(temp_prices[v], prices[u] + price).
// Crucial: We only read from the original prices array and only write to temp_prices. This ensures that all paths calculated in one iteration use exactly one more edge than the paths from the previous iteration. It's like taking a snapshot.
// Update: After iterating through all flights, copy temp_prices back to prices.
// Result: After the outer loop finishes, prices[dst] will contain the minimum cost to reach the destination in at most K+1 flights. If it's still infinity, the destination is unreachable.*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n,INT_MAX);
        distance[src] = 0;
        k = k + 1; // k -> stops, means k + 2 vertices invloved (+2 for start and the end) means k + 1edges  
        while(k--){
            vector<int> temp_distance = distance;
            for(auto& flight : flights){
                if(distance[flight[0]] == INT_MAX) continue;
                temp_distance[flight[1]] = min(temp_distance[flight[1]], distance[flight[0]] + flight[2]);
            }
            distance = temp_distance;
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};

// // GPT code 
// // class Solution {
// // public:
// //     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
// //         // prices[i] stores the minimum cost to reach node i
// //         vector<long> prices(n, LONG_MAX);
// //         prices[src] = 0;

// //         // We run the relaxation K+1 times (for K+1 edges)
// //         for (int i = 0; i <= k; ++i) {
// //             vector<long> temp_prices = prices;
// //             for (const auto& flight : flights) {
// //                 int u = flight[0];
// //                 int v = flight[1];
// //                 int price = flight[2];

// //                 if (prices[u] != LONG_MAX) {
// //                     temp_prices[v] = min(temp_prices[v], prices[u] + price);
// //                 }
// //             }
// //             prices = temp_prices;
// //         }

// //         if (prices[dst] == LONG_MAX) {
// //             return -1;
// //         }
// //         return prices[dst];
// //     }
// // };

// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
//         // Create the adjacency list to represent airports and flights as a graph
//         vector<pair<int, int>> adj[n];
//         for (auto it : flights)
//         {
//             adj[it[0]].push_back({it[1], it[2]});  // Add an edge from source to destination with the weight (cost)
//         }

//         // Create a queue to store the node, its distance from the source, and the number of stops
//         queue<pair<int, pair<int, int>>> q;
        
//         q.push({0, {src, 0}});  // Push the source node with 0 stops and 0 cost

//         // Create a distance array to store the minimum cost to reach each node
//         vector<int> dist(n, 1e9);
//         dist[src] = 0;  // The distance from source to itself is 0

//         // BFS traversal with a queue to process the nodes
//         while (!q.empty())
//         {
//             auto it = q.front();
//             q.pop();
//             int stops = it.first;  // Number of stops so far
//             int node = it.second.first;  // Current node
//             int cost = it.second.second;  // Cost to reach the current node

//             // If the number of stops exceeds K, continue to the next iteration
//             if (stops > K)
//                 continue;

//             // Iterate over all the adjacent nodes (next destinations)
//             for (auto iter : adj[node])
//             {
//                 int adjNode = iter.first;  // Next destination node
//                 int edW = iter.second;  // Cost of the flight to the next destination

//                 // If a shorter path to the adjacent node is found, update the distance
//                 if (cost + edW < dist[adjNode] && stops <= K)
//                 {
//                     dist[adjNode] = cost + edW;  // Update the distance
//                     q.push({stops + 1, {adjNode, cost + edW}});  // Push the new node with updated stops and cost
//                 }
//             }
//         }

//         // If destination node is unreachable, return -1
//         if (dist[dst] == 1e9)
//             return -1;

//         return dist[dst];  // Return the minimum cost to reach the destination
//     }
// };
