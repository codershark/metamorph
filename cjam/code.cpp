#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> getTrace(vector<vector<int>>& matrix, int N) {
    int trace = 0;
    for (int i = 0; i < N; i++) {
        trace += matrix[i][i];
    }
    int rows_repeated = 0;
    for (int i = 0; i < N; i++) {
        unordered_set<int> row_visited;
        for (int j = 0; j < N; j++) {
            if (row_visited.find(matrix[i][j]) != row_visited.end()) {
                rows_repeated++;
                break;
            }
	    row_visited.insert(matrix[i][j]);
        }
    }
    int cols_repeated = 0;
    for (int i = 0; i < N; i++) {
        unordered_set<int> cols_visited;
        for (int j = 0; j < N; j++) {
            if (cols_visited.find(matrix[j][i]) != cols_visited.end()) {
                cols_repeated++;
                break;
            }
	    cols_visited.insert(matrix[j][i]);
        }
    }
    
    return {trace, rows_repeated, cols_repeated};
}

int main() {
    int tests, n, k, r, c;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        cin >> n;
        vector<vector<int> > matrix(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }
        vector<int> ans = getTrace(matrix, n);
        cout << "Case #" << t + 1 << ": " << ans[0] << " " 
        << ans[1] << " " << ans[2] << endl;
    }
}

