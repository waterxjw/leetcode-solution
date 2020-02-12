#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0)return 0;
        int ans=INT_MAX,lo=0,hi=0,sum=nums[0];
        while(true){
            if(sum>=s){
                while(true){
                    if(sum-nums[hi]<s){
                        break;
                    }else{
                        hi--;
                        sum-=nums[hi];
                    }
                }
            }else{
                while(true){
                    if(hi==nums.size()-1){
                        break;
                    }
                    hi++;
                    sum+=nums[hi];
                    if(sum>=s)break;
                }
            }
            if(sum>=s){
                if(hi-lo+1<ans)ans=hi-lo+1;
                sum-=nums[lo];
                lo++;
            }else{
                break;
            }
            if(sum==0)break;
        }
        return ans==INT_MAX?0:ans;
    }
};