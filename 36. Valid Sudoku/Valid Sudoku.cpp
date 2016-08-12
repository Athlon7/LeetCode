// class Solution
// {
// public:
//     bool isValidSudoku(vector<vector<char>>& board)
//     {
//         // check rows
//         for(vector<vector<char>>::iterator i = board.begin();i != board.end();++i)
//         {
//         	vector<bool> flag(9, false);
//         	for(vector<char>::iterator j = (*i).begin(); j != (*i).end();++j)        	
//         		if(*j != '.')
//         		{
//         			if(flag[*j - 49] == true)
//         				return false;
//         			else
//         				flag[*j - 49] = true;
//         		}
//         }

//         // check colums
//         for(int j = 0;j < 9;++j)
//         {
//         	vector<bool> flag(9, false);
//         	for(int i = 0;i < 9;++i)        	
//         		if(board[i][j] != '.')
//         		{
//         			if(flag[board[i][j] - 49] == true)
//         				return false;
//         			else
//         				flag[board[i][j] - 49] = true;
//         		}
//         }

//         // check blocks
//         for(int row = 0;row < 9;row += 3)
//         	for(int col = 0;col < 9;col += 3)
//         	{
//         		vector<bool> flag(9, false);
//         		for(int i = row;i < row + 3;++i)
//         			for(int j = col;j < col + 3;++j)
//         				if(board[i][j] != '.')
//         				{
//         					if(flag[board[i][j] - 49] == true)
//         						return false;
//         					else
//         						flag[board[i][j] - 49] = true;
//         				}
//         	}

//         return true;
//     }
// }; 

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int flags_row[9][9] = {}, flags_col[9][9] = {}, flags_block[9][9] = {};
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
};