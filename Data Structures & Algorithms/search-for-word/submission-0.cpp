class Solution {
public:
    bool dfs(vector<vector<char>> &board, string &word, int row, int col, int i, vector<vector<int>> &vis){
        int rows = board.size();
        int cols = board[0].size();
        if(i==word.length()) return true;
        if(row<0 || col<0 || row>=rows || col>=cols || board[row][col]!=word[i] || vis[row][col]==1 ) return false;
        vis[row][col]=1;
        bool res = (dfs(board,word,row+1,col,i+1,vis) ||
        dfs(board,word,row-1,col,i+1,vis) || 
        dfs(board,word,row,col+1,i+1,vis) ||
        dfs(board,word,row,col-1,i+1,vis));
        vis[row][col]=0;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
       int rows = board.size();
       int cols = board[0].size();
       vector<vector<int>> vis(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,word,i,j,0,vis)) return true;
                }
                
            }
        }
        return false;
    }
};
