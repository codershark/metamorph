// Source : https://oj.leetcode.com/problems/<insert problem>/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
* Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
* 
* Example:
* Given a / b = 2.0, b / c = 3.0.
* queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
* return [6.0, 0.5, -1.0, 1.0, -1.0 ].
* 
* The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.
* 
* According to the example above:
* 
* equations = [ ["a", "b"], ["b", "c"] ],
* values = [2.0, 3.0],
* queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
*               
**********************************************************************************/

class Solution {
public:
    unordered_map<string, pair<string, double>> parent;
    
    string dsu_find(const string& node, double& value) {
        if (parent.find(node) == parent.end()) {
            parent[node] = {node, value};
            return node;
        }
        string p = parent[node].first;
        if (p == node) return p;
        value = value * parent[node].second;
        return dsu_find(p, value);
    }
    
    void dsu_union(const string& a, const string& b, double value) {
        double pavalue = 1.0, pbvalue = 1.0;
        string pa = dsu_find(a, pavalue);
        string pb = dsu_find(b, pbvalue);
        if (pa != pb) {
            parent[pb].first = pa;
            //pa/pb=(a*pavalue)/(b*pbvalue)=(b*value*pavalue)/(b*pbvalue)=pavalue*value/pbvalue
            parent[pb].second = pavalue * value / pbvalue;
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            dsu_union(equations[i][0], equations[i][1], values[i]);
        }
        vector<double> ans;
        for (int i=0; i < queries.size(); i++){
            string a = queries[i][0];
            string b = queries[i][1];
            if (parent.find(a) == parent.end() || parent.find(b) == parent.end()) {
                ans.push_back(-1.0);
            } else {
                double pavalue = 1.0, pbvalue = 1.0;
                string pa = dsu_find(a, pavalue);
                string pb = dsu_find(b, pbvalue);
                if (pa != pb) {
                    ans.push_back(-1.0);
                } else {
					//pa==pb, pa/a=pavalue,pb/b=pbvalue
					//hence a/b=pbvalue/pavalue
                    ans.push_back(pbvalue / pavalue);
                }
            }
        }
        return ans;
        
    }
};