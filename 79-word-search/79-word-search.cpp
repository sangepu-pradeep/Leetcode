class Solution {
    private:
    int dx[4]={1, -1, 0, 0};
    int dy[4]={0, 0, -1, 1};
  
    
public:
    bool check(int x, int y, int m, int n){
        return (x>=0 && x<=m-1 && y>=0 && y<= n-1);
    }
    bool fun(int i, int j, vector<vector<char>>& board, string& word, int m, int n, int l){
       if(l==word.size()) return true;
       if(check(i, j, m, n)==false) return false;
       
       if(board[i][j]!=word[l]) return false;
        board[i][j]='#';
        
        for(int k=0; k<4; k++){
               if(fun(i+dx[k], j+dy[k], board, word, m, n, l+1)==true) return true;
        }
        board[i][j]=word[l];
        
        return false;
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(fun(i, j, board, word, m, n, 0)){
                    return true;
                }
            }
        }
     
        return false;
       
    }
};