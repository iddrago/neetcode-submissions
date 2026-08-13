class Solution {
   public:
    void dfs(int row, int col, vector<vector<int>>& vis, int prevHeight,
             vector<vector<int>>& heights) {
        int n = vis.size();
        int m = vis[0].size();
        if (row < 0 || col < 0 || row > n - 1 || col > m - 1 || vis[row][col] == 1 || heights[row][col]<prevHeight){
            return;
        }
        vis[row][col]=1;
        int delRow[]={0,+1,0,-1};
        int delCol[]={-1,0,+1,0};
        for(int i=0;i<4;i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            dfs(nrow,ncol,vis,heights[row][col],heights);
        }
     }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> vispac(n, vector<int>(m, 0));
        vector<vector<int>> visatl(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++) {
            dfs(0, i, vispac, heights[0][i],heights);
            dfs(n - 1, i, visatl, heights[n - 1][i],heights);
        }
        for (int j = 0; j < n; j++) {
            dfs(j, 0, vispac, heights[j][0],heights);
            dfs(j, m - 1, visatl, heights[j][m - 1],heights);
        }

        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vispac[i][j] && visatl[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
