class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //checking rows index 0 to 8
        for(int i=0;i<9;i++){
            unordered_set <char> seen;
            for(int j=0;j<9;j++){
               if(board[i][j] == '.') continue;
               if(seen.count(board[i][j])){
                return false;
               }
               seen.insert(board[i][j]);
            }
        }
        //Check all columns
        for(int i=0;i<9;i++){
          unordered_set <char> seen;
          for(int j=0;j<9;j++){
            if(board[j][i] == '.') continue;
            if(seen.count(board[j][i])){
                return false;
               }
               seen.insert(board[j][i]);
          }
        }
        // Check all 3×3 boxes
        // 3 x 3 square is 9
        for(int i=0;i<9;i++){
            unordered_set<char> seen;
            for(int j=0;j<3;j++){
                for(int k = 0; k<3;k++){
                    int row = (i/3) * 3 + j;
                    int col = (i%3) * 3 + k;
                    if (board[row][col] == '.') continue;
                    if (seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
                
            }
        }
        return true;
    }
    
};
