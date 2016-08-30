class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> ans;
        if(matrix.size() == 1 && matrix[0].size() == 0)
        	return ans;
        int num = matrix.size() * matrix[0].size();
        int up = 0, down = matrix.size(), left = 0, right = matrix[0].size();

        while(ans.size() != num)
        {
        	for(int i = left;i < right;++i)
        		ans.push_back(matrix[up][i]);
        	++up;
        	for(int i = up;i < down;++i)
        		ans.push_back(matrix[i][right - 1]);
        	--right;
        	for(int i = right - 1;i >= left;--i)
        		ans.push_back(matrix[down - 1][i]);
        	--down;
        	for(int i = down - 1;i >= up;--i)
        		ans.push_back(matrix[i][left]);
        	++left;
        }
        return ans;
    }
};