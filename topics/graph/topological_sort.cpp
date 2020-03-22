// Source : https://oj.leetcode.com/problems/course-schedule-ii/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
* There are a total of n courses you have to take, labeled from 0 to n-1.
* Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
* Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
* 
* There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
* 
* Example 1:
* 
* Input: 2, [[1,0]] 
* Output: [0,1]
* Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
*              course 0. So the correct course order is [0,1] .
*               
**********************************************************************************/

class Solution {
public:
    struct GNode {
        vector<int> neighbors;
        int in_degree = 0;
    };
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<GNode> graph(numCourses);
        for (const auto& entry : prerequisites) {
            graph[entry[1]].neighbors.push_back(entry[0]);
            graph[entry[0]].in_degree++;
        }
        queue<int> q;
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[i].in_degree == 0) q.push(i);
        }
        vector<int> result;
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            result.push_back(temp);
            for (auto n : graph[temp].neighbors) {
                graph[n].in_degree--;
                if (graph[n].in_degree == 0) q.push(n);
            }
        }
        return result.size() == numCourses ? result : vector<int>(0);
    }
};
