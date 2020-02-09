#include<vector>
using namespace std;
/**
 * 乘积有其特殊性，因此不仅要维护最大还要维护最小
*/
class Solution {
public:
    int max_t(int a,int b,int c){
        if(a>=b&&a>=c)return a;
        if(c>=b&&c>=a)return c;
        if(b>=a&&b>=c)return b;
        return 0;
    }
    int min_t(int a,int b,int c){
        if(a<=b&&a<=c)return a;
        if(c<=b&&c<=a)return c;
        if(b<=a&&b<=c)return b;
        return 0;
    }
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int old_max=nums[0];
        int old_min=nums[0];
        for(int i=1;i<nums.size();i++){
            int temp1=old_max*nums[i];
            int temp2=old_min*nums[i];
            old_max=max_t(temp1,temp2,nums[i]);
            old_min=min_t(temp1,temp2,nums[i]);
            if(old_max>ans)ans=old_max;
        }
        return ans;
    }
};