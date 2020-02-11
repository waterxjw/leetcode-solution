#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0,right=nums.size()-1,cur=0;
        while(cur<=right){
            if(nums[cur]==0){
                nums[cur]=nums[left];
                nums[left]=0;
                left++;
                cur++;//这里有点坑。因为cur从左边遍历过来，所以不担心换回来一个2，而下面这种情况可能换回来一个0，因此cur不动，再来一遍
            }else if(nums[cur]==2){
                nums[cur]=nums[right];
                nums[right]=2;
                right--;
            }else{
                cur++;
            }
        }
    }
};