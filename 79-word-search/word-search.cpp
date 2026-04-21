class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word,
             vector<vector<bool>>& visited, int x, int y, int k) {

        if (k == word.size()) return true;

        // boundary + visited + mismatch check
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() ||
            visited[x][y] || board[x][y] != word[k]) {
            return false;
        }

        visited[x][y] = true;

        bool found =
            dfs(board, word, visited, x + 1, y, k + 1) ||
            dfs(board, word, visited, x - 1, y, k + 1) ||
            dfs(board, word, visited, x, y + 1, k + 1) ||
            dfs(board, word, visited, x, y - 1, k + 1);

        visited[x][y] = false; // backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, visited, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};