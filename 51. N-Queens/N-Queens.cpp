class Solution
{
public:
    void fill(int n, int row, int pos, vector<vector<string> > &ans)
    {
        static vector<pair<int, int> > pos_stack;

        // check if this position is available
        for(int i = 0;i < pos_stack.size();++i)
        	if(pos_stack[i].second == pos ||
        		pos_stack[i].first + pos_stack[i].second == row + pos ||
        		pos_stack[i].second - pos_stack[i].first == pos - row)
        		return;

        pos_stack.push_back(make_pair(row, pos));
        // the answer is found
        if(row == n - 1)
        {
        	string temp(n, '.');
            vector<string> solu(n, temp);
            for(int i = 0;i < pos_stack.size();++i)
            {
                solu[pos_stack[i].first][pos_stack[i].second] = 'Q';
            }
            ans.push_back(solu);
        }
        else
        {
        	++row;
        	for(int i = 0;i < n;++i)
        		fill(n, row, i, ans);
        }

        pos_stack.pop_back();
    }

    vector<vector<string> > solveNQueens(int n)
    {       
        vector<vector<string> > ans;
        
        for(int i = 0;i < n;++i)
        {            
            fill(n, 0, i, ans);
        }
        return ans;
    }
};

// 将四个方向分别存在4个vector中，可以快速查表，节省时间
class Solution
{
private:
	vector<int> cols;
	vector<int> dia1;
	vector<int> dia2;
public:
    void fill(int n, int row, int pos, vector<vector<string> > &ans)
    {
        static vector<pair<int, int> > pos_stack;        

        // check if this position is available
        if(!cols[pos] || !dia1[row + pos] ||
            !dia2[pos - row + n - 1])
            return;

        pos_stack.push_back(make_pair(row, pos));
        cols[pos] = 0;
        dia1[row + pos] = 0;
        dia2[pos - row + n - 1] = 0;

        // the answer is found
        if(row == n - 1)
        {
            string temp(n, '.');
            vector<string> solu(n, temp);
            for(int i = 0;i < pos_stack.size();++i)
            {
                solu[pos_stack[i].first][pos_stack[i].second] = 'Q';
            }
            ans.push_back(solu);
        }
        else
        {
            for(int i = 0;i < n;++i)
                fill(n, row + 1, i, ans);
        }
        pos_stack.pop_back();
        cols[pos] = 1;
        dia1[row + pos] = 1;
        dia2[pos - row + n - 1] = 1;
    }

    vector<vector<string> > solveNQueens(int n)
    {       
        vector<vector<string> > ans;
        
        cols.assign(n, 1);
        dia1.assign(2 * n - 1, 1);
        dia2.assign(2 * n - 1, 1);

        for(int i = 0;i < n;++i)
        {            
            fill(n, 0, i, ans);
        }
        return ans;
    }
};