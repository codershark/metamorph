// Source : https://oj.leetcode.com/problems/course-schedule/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
* There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
* 
* Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
* 
* Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
* 
*  
* 
* Example 1:
* 
* Input: numCourses = 2, prerequisites = [[1,0]]
* Output: true
* Explanation: There are a total of 2 courses to take. 
*              To take course 1 you should have finished course 0. So it is possible.
*               
**********************************************************************************/

class Solution {
public:
    bool hasCycle(const unordered_map<int, vector<int>>& graph, unordered_set<int>& visited,
                 unordered_set<int>& path, int node) {
        if (path.find(node) != path.end()) {
            return true;
        }
        if (visited.find(node) != visited.end()) {
            return false;
        }
        visited.insert(node);
        path.insert(node);
        for (auto neigh : graph.at(node)) {
            if (hasCycle(graph, visited, path, neigh)) return false;
        }
        path.erase(node);
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        for (auto entry : prerequisites) {
            graph[entry[1]].push_back(entry[0]);
            graph[entry[0]];
        }
        int i = 0;
        while (graph.size() < numCourses && i < numCourses) {
            graph[i];
            ++i;
        }
        unordered_set<int> visited;
        unordered_set<int> path;
        for (auto entry : graph) {
            if (hasCycle(graph, visited, path, entry.first)) return false;
        }
        return true;
    }
};