class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {        
        int blkNum = 0;

        for(int i = 0;i < 9;++i)
        {
        	for(int j = 0; j < 9;++j)        	
        		if(board[i][j] != '.')
        		{
        			// rows
        			if(flags_row[i][board[i][j] - 49] != 0)
        				return false;
        			else 
        				flags_row[i][board[i][j] - 49] = 1;

        			// cols
        			if(flags_col[j][board[i][j] - 49] != 0)
        				return false;
        			else 
        				flags_col[j][board[i][j] - 49] = 1;

        			// blocks
        			if(i < 3 && j < 3)
        				blkNum = 0;
        			else if(i < 3 && j < 6 && j >= 3)
        				blkNum = 1;
        			else if(i < 3 && j < 9 && j >= 6)
        				blkNum = 2;
        			else if(i < 6 && i >= 3 && j < 3)
        				blkNum = 3;
        			else if(i < 6 && i >= 3 && j < 6 && j >= 3)
        				blkNum = 4;
        			else if(i < 6 && i >= 3 && j < 9 && j >= 6)
        				blkNum = 5;
        			else if(i < 9 && i >= 6 && j < 3)
        				blkNum = 6;
        			else if(i < 9 && i >= 6 && j < 6 && j >= 3)
        				blkNum = 7;
        			else if(i < 9 && i >= 6 && j < 9 && j >= 6)
        				blkNum = 8;

        			if(flags_block[blkNum][board[i][j] - 49] != 0)
        				return false;
        			else 
        				flags_block[blkNum][board[i][j] - 49] = 1;
        		}
        }
        return true;
	};

    void solve(vector<vector<char>>& board)
    {
    	static blk_cnt = 0;

    	
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        int flags_row[9][9] = {}, flags_col[9][9] = {}, flags_block[9][9] = {};
        int blkNum = 0;

        if(!isValidSudoku(board))
        	return;



    }
};