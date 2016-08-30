// �����������õ��Ĵ𰸣�����map�ṹ�洢��key�Ǳ����ĸ��vector
// value�Ǵ�string��vector������֮ǰʹ�õķֱ�洢��ܶࡣ
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

// ������һ����������㷨����ÿ��string����������ĸ��ͬ�ľͱ����һ����string
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

// �ٶ�push_back�����Ż������ٴ������Լ�ʡȥ����������
// �������Լ����ύ����������һ���죬��֪�����������ô����60ms��
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

// ���в�������hash��ģ���˵�������㷨������Ҫ���򣬲���Ҫ�Ա���������ַ���
// ֱ�ӱ�����������ȷ�������ַ����Ƿ���ĸ��ͬ���ǳ�����
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

// �Լ�����һ��
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
