#include<string>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int s_size=s.size();
        int dict_size=wordDict.size();
        vector<vector<bool>> dp(s_size,vector<bool>(s_size,false));
        for(int right=0;right<s_size;right++){
            for(int left=right;left>=0;left--){
                bool isCompose=false;
                for(int x=0;x<=right-left-1;x++){
                    if(dp[left][left+x]&&dp[left+x+1][right]){
                        dp[left][right]=true;
                        isCompose=true;
                        break;
                    }
                }
                if(isCompose)continue;
                string current(s.substr(left,right-left+1));
                for(int i=0;i<dict_size;i++){
                    if(current==wordDict[i]){
                        dp[left][right]=true;
                        break;
                    }
                }
            }
        }
        return dp[0][s_size-1];
    }
};