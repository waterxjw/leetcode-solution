#include<string>
#include<vector>
#include<stack>
using namespace std;
class Solution
{
public:
    bool isWord(string &s, vector<string> &wordDict)
    {
        int ans = false;
        for (int i = 0; i < wordDict.size(); i++)
        {
            if (s == wordDict[i])
            {
                ans = true;
                break;
            }
        }
        return ans;
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        int size = s.size();
        stack<pair<int, int>> stac;
        vector<string> ans;
        string current;
        int first = 0;
        for (; first < size; first++)
        {
            string tmp(s.substr(0, first + 1));
            if (isWord(tmp, wordDict))
            {
                stac.push({0, first});
                current.append(tmp);
                break;
            }
        }
        if (stac.empty())
            return ans;
        while (!stac.empty())
        {
            if (stac.top().second != size - 1)
            {
                int begin = stac.top().second + 1;
                int end;
                for (end = begin; end < size; end++)
                {
                    string temp(s.substr(begin, end - begin + 1));
                    if (isWord(temp, wordDict))
                    {
                        stac.push({begin, end});
                        current.append(" ");
                        current.append(temp);
                        break;
                    }
                }
                if (end != size)
                    continue;
            }
            //先装进ans，再回溯
            ans.push_back(current);
            current = vector<string>(current);
            while (!stac.empty())
            {
                stac.pop();
                current.pop_back();
                if (stac.empty())
                    break;
                int lo = stac.top().first, hi = stac.top().second;
                bool isBreak = false;
                for (hi = hi + 1; hi < size; hi++)
                {
                    int i = lo, j = hi;
                    bool isP = true;
                    while (i < j)
                    {
                        if (s[i] != s[j])
                        {
                            isP = false;
                            break;
                        }
                        i++;
                        j--;
                    }
                    if (isP)
                    {
                        isBreak = true;
                        break;
                    }
                }
                if (isBreak)
                {
                    stac.pop();
                    current.pop_back();
                    stac.push({lo, hi});
                    current.push_back(s.substr(lo, hi - lo + 1));
                    break;
                }
            }
        }
        return ans;
    }
};