// Source : https://oj.leetcode.com/problems/<insert problem>/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
*               
**********************************************************************************/

struct edge {int src, des, weight;};

pair<bool,vector<int>> bellmanFord(vector<edge> graph,int vertex,int source) {
    vector<int> distances(vertex,INT_MAX);
    distances[source] = 0;
    for (int i = 0; i < vertex-1; i++) {
        for (int j = 0; j < graph.size(); j++) {
            if (distances[graph[j].des] > distances[graph[j].src] + graph[j].weight){
                distances[graph[j].des] = distances[graph[j].src] + graph[j].weight;
            }
        }
    }
    for(int j = 0; j < graph.size(); j++) {
        if(distances[graph[j].des] > distances[graph[j].src] + graph[j].weight){
            return {false, vector<int>()};
        }
    }
    return {true, distances};
}
