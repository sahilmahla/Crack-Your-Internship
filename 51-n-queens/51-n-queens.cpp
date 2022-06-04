class Solution {
public:
    bool isPossible(vector<string>& board ,int row ,int col,int n){
        // colunn
        for(int i = row-1;i>=0;i--){
            if(board[i][col] == 'Q')
                return false;
        }
        
        for(int i = row-1,j=col-1;i>=0 && j>= 0;i--,j--){
            if(board[i][j] == 'Q')
                return false;
        }
        for(int i = row-1,j = col+1;i>=0 && j<n;i--,j++){
            if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void nQueenHelper(int n,vector<vector<string>>& ans, vector<string>& board, int row){
        if(row == n){
            ans.push_back(board);
            return;
        }
        
        for(int j = 0;j<n;j++){
            if(isPossible(board,row,j,n)){
                board[row][j] = 'Q';
                nQueenHelper(n,ans,board,row+1);
                board[row][j] = '.';
            }
        }
        return;
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        nQueenHelper(n,ans,board,0);
        return ans;
    }
};