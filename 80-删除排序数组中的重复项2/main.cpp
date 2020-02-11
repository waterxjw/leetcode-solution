#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int repeat_num=0;
        //val times
        pair<int,int> previous={nums[0],1};
        for(int i=1;i<nums.size();i++){
            if(nums[i]==previous.first){
                if(previous.second==1){
                    previous.second=2;
                    nums[i-repeat_num]=nums[i];
                }else if(previous.second==2){
                    repeat_num++;
                }
            }else{
                previous={nums[i],1};
                nums[i-repeat_num]=nums[i];
            }
        }
        return nums.size()-repeat_num;
    }
};