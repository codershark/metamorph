// Source : https://oj.leetcode.com/problems/<insert problem>/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.

Dijkstra's algorithm uses a priority queue to continually search the next node with the lowest cost.

If we've come to a node and it has a lower recorded cost or we've taken too many steps, we don't need to search it. If we reach our destination, because we are searching in order of lowest cost first, it must have the lowest cost.

Otherwise, for every outbound flight from node that is better, we'll add it to our priority queue of things to search.

Time Complexity: O(E+nlogn), where E is the total number of flights.

Space Complexity: O(n), the size of the heap.
*               
**********************************************************************************/

class Solution {
    struct Node {
        Node(int i, int c, int s): id(i), cost(c), stops(s) {}
       
        int id = 0;
        int cost = 0;
        int stops = 0;
        bool operator<(const Node& rhs) const {
            return cost < rhs.cost;
        }
    };
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> cost(n, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }
        priority_queue<Node> pq;
        pq.push({src, 0, 0});
        cost[src] = 0;
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int u = curr.id;
            for (auto neigh : graph[u]) {
                int v = neigh.first;
                int w = neigh.second;
                if (cost[v] > cost[u] + w && curr.stops < K + 1) {
                    cost[v] = cost[u] + w;
                    pq.push({v, cost[v], curr.stops + 1});
                }
            }
        }
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};