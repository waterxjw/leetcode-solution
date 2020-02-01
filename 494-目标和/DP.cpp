#include <vector>
#include <queue>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(S<-1000||S>1000)return 0;
        int dp[2001];
        int next[2001];
        for(int i=0;i<2001;i++){
            dp[i]=0;
            if(i-1000==nums[0])dp[i]++;
            if(1000-i==nums[0])dp[i]++;
        }
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<2001;j++){
                next[j]=((j-nums[i]>=0)?dp[j-nums[i]]:0)+((j+nums[i]<2001)?dp[j+nums[i]]:0);
            }
            for(int j=0;j<2001;j++){
                dp[j]=next[j];
            }
        }
        return dp[S+1000];
    }
};