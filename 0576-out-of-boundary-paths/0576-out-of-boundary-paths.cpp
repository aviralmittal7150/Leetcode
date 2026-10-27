class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[startRow][startColumn] = 1;

        int result = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int move = 1; move <= maxMove; move++) {
            vector<vector<int>> next(m, vector<int>(n, 0));

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[i][j] == 0) continue;

                    for (int k = 0; k < 4; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];

                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                            result = (result + dp[i][j]) % MOD;
                        } else {
                            next[nr][nc] =
                                (next[nr][nc] + dp[i][j]) % MOD;
                        }
                    }
                }
            }

            dp = next;
        }

        return result;
    }
};