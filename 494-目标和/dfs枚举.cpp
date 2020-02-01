#include <vector>
#include <queue>
#include<unordered_set>
using namespace std;
class Solution {
public:
    long dfs(vector<int>& nums,long remain,int current_index){
        if(current_index==nums.size()-1){
            int ans=0;
            if(nums[current_index]==remain)ans++;
            if(nums[current_index]*-1==remain)ans++;
            return ans;
        }
        return dfs(nums,remain-nums[current_index],current_index+1)+dfs(nums,remain+nums[current_index],current_index+1);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        return dfs(nums,S,0);
    }
};