// Source : https://oj.leetcode.com/problems/<insert problem>/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
* 332. Reconstruct Itinerary
* 
* Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
* 
* Note:
* 
* If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
* All airports are represented by three capital letters (IATA code).
* You may assume all tickets form at least one valid itinerary.
* Example 1:
* 
* Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
* Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
* Example 2:
* 
* Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
* Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
* Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
*              But it is larger in lexical order.
*               
**********************************************************************************/

class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> ans;

    void dfs(string node) {
        while (!graph[node].empty()) {
            auto curr = graph[node].top();
            graph[node].pop();
            dfs(curr);
        }
        ans.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};