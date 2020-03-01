// Source : https://oj.leetcode.com/problems/sort-characters-by-frequency/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
* Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
* A region is captured by flipping all 'O's into 'X's in that surrounded region.
* For example,
* X X X X
* X O O X
* X X O X
* X O X X
* After running your function, the board should be:
* X X X X
* X X X X
* X X X X
* X O X X
*               
**********************************************************************************/

class Solution {
public:
    struct PairHash {
      public:
        size_t operator()(const pair<int, int> &x) const {
            auto h = hash<int>();
            return h(x.first) ^ h(x.second);
        }
    };
    void dfs(vector<vector<char>>& board, unordered_set<pair<int, int>, PairHash>& visited, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        if (board[i][j] == 'X' || visited.find({i, j}) != visited.end()) return;
        visited.insert({i, j});
        board[i][j] = 'I';
        dfs(board, visited, i-1, j);
        dfs(board, visited, i+1, j);
        dfs(board, visited, i, j-1);
        dfs(board, visited, i, j+1);
        return;
    }
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        if (r < 2) return;
        int c = board[0].size();
        if (c < 2) return;
        for (int i = 0; i < r; ++i) {
            if (board[i][0] == 'O') board[i][0] = 'I';
            if (board[i][c-1] == 'O') board[i][c-1] = 'I';
        }
        for (int j = 0; j < c; ++j) {
            if (board[0][j] == 'O') board[0][j] = 'I';
            if (board[r-1][j] == 'O') board[r-1][j] = 'I';
        }
        unordered_set<pair<int, int>, PairHash> visited;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (board[i][j] == 'I') {
                    dfs(board, visited, i, j);
                }
            }
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (board[i][j] == 'I') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};
