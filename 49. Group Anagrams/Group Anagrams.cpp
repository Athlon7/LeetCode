// 讨论区启发得到的答案，采用map结构存储，key是标记字母的vector
// value是存string的vector，比我之前使用的分别存储快很多。
class Solution
{
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs)
    {
        vector<vector<string> > ans;
        vector<int> alph(26, 0);
        map<vector<int>, vector<string> > amap;

        if(strs.size() == 1)
        {
            ans.resize(1);
            ans[0].push_back(strs[0]);
            return ans;
        }
        
        for(int i = 0;i < strs.size();++i)
        {
            alph.assign(26, 0);
            for(int j = 0;j < strs[i].size();++j)
            {
                ++alph[strs[i][j] - 'a'];
            }
            amap[alph].push_back(strs[i]);
        }

        map<vector<int>, vector<string> >::iterator iter = amap.begin();
        while(iter != amap.end())
        {
            ans.push_back(iter->second);
            iter++;
        }
        return ans;
    }
};

// 另外有一种先排序的算法，对每个string排序，这样字母相同的就变成了一样的string
class Solution
{
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs)
    {
        vector<vector<string> > ans;
        map<string, vector<string> > amap;
        string sorted;

        if(strs.size() == 1)
        {
            ans.resize(1);
            ans[0].push_back(strs[0]);
            return ans;
        }
        
        for(int i = 0;i < strs.size();++i)
        {
        	sorted = strs[i];
        	sort(sorted.begin(), sorted.end());

        	amap[sorted].push_back(strs[i]);
        }

        map<string, vector<string> >::iterator iter = amap.begin();
        while(iter != amap.end())
        {
            ans.push_back(iter->second);
            iter++;
        }
        return ans;
    }
};

// 再对push_back进行优化，减少次数，以及省去结果输出遍历
// 经过我自己的提交，还不如上一个快，不知道提出者是怎么做到60ms的
class Solution
{
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs)
    {
        vector<vector<string> > ans;
        map<string, int> amap;
        string sorted;        
        int cnt = 1;

        if(strs.size() == 1)
        {
            ans.resize(1);
            ans[0].push_back(strs[0]);
            return ans;
        }
        
        for(int i = 0;i < strs.size();++i)
        {
        	sorted = strs[i];
        	sort(sorted.begin(), sorted.end());
        	if(amap[sorted] == 0)
        	{
        		amap[sorted] = cnt++;
        		vector<string> temp(1);
        		temp[0] = strs[i];
        		ans.push_back(temp);
        	}
        	else
        	{
        		ans[amap[sorted] - 1].push_back(strs[i]);
        	}
        }
        return ans;
    }
};

// 还有采用质数hash表的，据说是最快的算法，不需要排序，不需要对比数组或者字符串
// 直接比两个数就能确定两个字符串是否字母相同，非常厉害
class Solution
{
private:
	vector<int> primes = {2, 3, 5, 7, 11 ,13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 107};
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<int,int> map;
        vector<vector<string> >result;
        int count = 1;
        for(auto i : strs)
        {
            int hash = 1;
            for(int j = 0;j < i.size();++j)
            {
                hash *= primes[i[j] - 'a'];
            }
            if(map[hash] == 0)
            {
                vector<string> cur(1);
                cur[0] = i;
                result.push_back(cur);
                map[hash] = count++;
           }
            else
            result[map[hash]-1].push_back(i);
        }
        return result;
    }
};

// 自己改造一下
class Solution
{
private:
	vector<int> primes = {2, 3, 5, 7, 11 ,13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 107};
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<int, vector<string> > amap;
        vector<vector<string> >result;
        int count = 1;
        for(auto i : strs)
        {
            int hash = 1;
            for(int j = 0;j < i.size();++j)
            {
                hash *= primes[i[j] - 'a'];
            }            
            amap[hash].push_back(i);
        }

        for(auto i : amap)
        	result.push_back(i.second);
        return result;
    }
};
