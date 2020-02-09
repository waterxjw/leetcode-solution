#include<vector>
using namespace std;
/**
 * 算法的关键在于，当count为0使得抛弃不考虑前边元素时，众数不变（不管之前的候选众数是不是真的众数）
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(count==0)ans=nums[i];
            if(ans==nums[i])count++;
            else count--;
        }
        return ans;
    }
};