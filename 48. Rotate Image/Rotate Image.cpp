class Solution
{
public:
    void rotate(vector<vector<int> >& matrix)
    {
        // transpose the matrix first
        int temp, n = matrix.size();
        for(int i = 0;i < n;++i)
        {
        	for(int j = 0;j < n - i;++j)
        	{
        		temp = matrix[i][j];
        		matrix[i][j] = matrix[n - 1 - j][n - 1 - i];
        		matrix[n - 1 - j][n - 1 - i] = temp;
        	}
        }

        // then mirror the image
        for(int i = 0;i < ((n + 1) / 2);++i)
        {
        	swap(matrix[i], matrix[n - 1 - i]);
        }

        return;
    }
};


// with ultra space used
class Solution
{
public:
    void rotate(vector<vector<int> >& matrix)
    {
        vector<vector<int> > ans(matrix);
        int n = matrix.size();

        for(int i = 0;i < n;++i)
        {
        	for(int j = 0;j < n;++j)
        	{
        		ans[j][n - 1 - i] = matrix[i][j];
        	}
        }

        matrix.assign(ans.begin(), ans.end());
        return;
    }
};