#include<string>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int s_size=s.size();
        int dict_size=wordDict.size();
        vector<bool> dp(s_size+1,false);
        dp[0]=true;
        for(int i=1;i<=s_size;i++){
            for(int j=0;j<i;j++){
                if(dp[j]){
                    string current(s.substr(j,i-j));
                    for(int k=0;k<dict_size;k++){
                        if(current==wordDict[k]){
                            dp[i]=true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[s_size];
    }
};