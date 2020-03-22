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
    class GNode {
    public:
        vector<int> neighbors;
        int in_degree = 0;
    };
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0) return true;
        unordered_map<int, GNode> graph;
        for (auto entry : prerequisites) {
            graph[entry[1]].neighbors.push_back(entry[0]);
            graph[entry[0]].in_degree++;
        }
        queue<int> zero_dependency;
        for (auto entry : graph) {
            if (entry.second.in_degree > 0) continue;
            zero_dependency.push(entry.first);
        }
        int removedEdges = 0;
        while (!zero_dependency.empty()) {
            auto temp = zero_dependency.front();
            zero_dependency.pop();
            for (auto n : graph[temp].neighbors) {
                graph[n].in_degree--;
                removedEdges++;
                if (graph[n].in_degree == 0) {
                    zero_dependency.push(n);
                }
            }
        }
        return removedEdges == prerequisites.size();
    }
};