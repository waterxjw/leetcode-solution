#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int val_num=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                val_num++;
            }else{
                nums[i-val_num]=nums[i];
            }
        }
        return nums.size()-val_num;
    }
};