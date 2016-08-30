class Solution
{
public:
    int next_blk(vector<int>& height, int &pos, int floor)
    {
    	int i, water = 0;

    	for(i = pos + 1;i < height.size();++i)
    	{
    		if(height[i] > floor)
    		{
    			pos = i;
    			return water;
    		}
    		++water;
    	}

    	return 0;
    }
    
    int trap(vector<int>& height)
    {
        int water = 0, h = 0;
        vector<vector<int> > chart;

        for(int i = 0;i < height.size();++i)
        {
        	if(height[i] > h)
        	{
        		h = height[i];
        		chart.resize(h);
        	}

        	if(height[i] > 0)
        	{
        		for(int j = 0;j <= height[i] - 1;++j)
        		{
        			chart[j].push_back(i);
        		}        		
        	}
        }

        for(int i = 0;i < 3;++i)
        {
        	for(int j = 0;j < chart[i].size();++j)
        		cout << chart[i][j] << " ";
        	cout << endl;
        }

        for(int i = 0;i < h;++i)
        {        	
        	for(int j = 0;j < chart[i].size();++j)
        	{
        		if(j + 1 < chart[i].size() && chart[i][j + 1] -
        			chart[i][j] > 1)
        		{
        			water += chart[i][j + 1] - chart[i][j];
        			cout << "new water: " << chart[i][j + 1] - chart[i][j];
        			cout << " total water: " << water << endl;
        		}
        	}
        }
        

        return 0;
    }
};