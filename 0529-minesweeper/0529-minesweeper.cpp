
class Solution {
public:
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};

    void dfs(vector<vector<char>>& board, int r, int c) {
        int m = board.size();
        int n = board[0].size();

        int mines = 0;

        // Count neighbouring mines
        for(int i = 0; i < 8; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
               board[nr][nc] == 'M') {
                mines++;
            }
        }

        // If neighbouring mines exist
        if(mines > 0) {
            board[r][c] = '0' + mines;
            return;
        }

        // No neighbouring mines
        board[r][c] = 'B';

        // Reveal all neighbouring cells
        for(int i = 0; i < 8; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
               board[nr][nc] == 'E') {
                dfs(board, nr, nc);
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0];
        int c = click[1];

        if(board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }

        dfs(board, r, c);

        return board;
    }
};
