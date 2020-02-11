#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int previous=nums[0];
        int repeat_num=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==previous){
                repeat_num++;
            }else{
                previous=nums[i];
                nums[i-repeat_num]=nums[i];
            }
        }
        return nums.size()-repeat_num;
    }
};