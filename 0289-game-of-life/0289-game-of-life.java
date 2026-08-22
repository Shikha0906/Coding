class Solution {
    public void gameOfLife(int[][] board) {
        int r = board.length;
        int c = board[0].length;
        int[][] currBoard = new int[r][c];
        
        
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                currBoard[i][j] = board[i][j];
        
        
        for (int i = 0; i < r; i++) {
            int nxtRow = i + 1;
            int prevRow = i - 1;
            
            
            boolean isNxtRowInRange = nxtRow < r;
            boolean isPrevRowInRange = prevRow >= 0;
            
            
            for (int j = 0; j < c; j++) {
                int liveNeighbors = 0;
                int nxtCol = j + 1;
                int prevCol = j - 1;
                
                
                boolean isNxtColInRange = nxtCol < c;
                boolean isPrevColInRange = prevCol >= 0;
                
                
                if (isNxtRowInRange) {
                    liveNeighbors += currBoard[nxtRow][j];
                    
                    
                    if (isPrevColInRange)
                        liveNeighbors += currBoard[nxtRow][prevCol];
                    
                    
                    if (isNxtColInRange)
                        liveNeighbors += currBoard[nxtRow][nxtCol];
                }
                
                
                if (isPrevRowInRange) {
                    liveNeighbors += currBoard[prevRow][j];
                    
                    
                    if (isPrevColInRange)
                        liveNeighbors += currBoard[prevRow][prevCol];
                    
                    
                    if (isNxtColInRange)
                        liveNeighbors += currBoard[prevRow][nxtCol];
                }
                
                
                if (isPrevColInRange)
                    liveNeighbors += currBoard[i][prevCol];
                
                
                if (isNxtColInRange)
                    liveNeighbors += currBoard[i][nxtCol];
                
                
                if (currBoard[i][j] == 1)
                    board[i][j] = liveNeighbors == 2 || liveNeighbors == 3 ? 1 : 0;
                else
                    board[i][j] = liveNeighbors == 3 ? 1 : 0;
            }
        }
    }
}