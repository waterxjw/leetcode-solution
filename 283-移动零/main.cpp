#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_num=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero_num++;
            }else{
                nums[i-zero_num]=nums[i];
            }
        }
        for(int i=0;i<zero_num;i++){
            nums[nums.size()-1-i]=0;
        }
    }
};