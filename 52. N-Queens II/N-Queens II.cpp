class Solution
{
private:
    vector<int> cols;
    vector<int> dia1;
    vector<int> dia2;
public:
    void fill(int n, int row, int pos, int &ans)
    {
        // check if this position is available
        if(!cols[pos] || !dia1[row + pos] ||
            !dia2[pos - row + n - 1])
            return;
        
        cols[pos] = 0;
        dia1[row + pos] = 0;
        dia2[pos - row + n - 1] = 0;

        // the answer is found
        if(row == n - 1)
        {
            ++ans;
        }
        else
        {
            for(int i = 0;i < n;++i)
                fill(n, row + 1, i, ans);
        }
        cols[pos] = 1;
        dia1[row + pos] = 1;
        dia2[pos - row + n - 1] = 1;
    }

    int totalNQueens(int n)
    {
        int ans = 0;

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