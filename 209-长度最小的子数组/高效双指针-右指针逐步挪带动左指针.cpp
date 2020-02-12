#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0)return 0;
        int ans=INT_MAX,lo=0,hi=0,sum=0;
        for(;hi<nums.size();hi++){
            sum+=nums[hi];
            while(true){
                if(sum-nums[lo]>=s){
                    sum-=nums[lo];
                    lo++;
                }else{
                    break;
                }
            }
            if(sum>=s){
                ans=min(ans,hi-lo+1);
            }
        }
        return ans==INT_MAX?0:ans;
    }
};