#include<vector>
using namespace std;
class Solution {
private:
    int part(vector<int>& nums,int lo,int hi){
        int val=nums[lo];
        int left=lo,right=hi;
        while(true){
            for(;left<hi;left++){
                if(nums[left]>val)break;
            }
            for(;right>lo;right--){
                if(nums[right]<val)break;
            }
            if(left>=right){
                nums[lo]=nums[right];
                nums[right]=val;
                return right;
            }
            int temp=nums[left];
            nums[left]=nums[right];
            nums[right]=temp;
        }
        return -1;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target_pos=nums.size()-k;
        int lo=0,hi=nums.size()-1;
        while(true){
            int cur=part(nums,lo,hi);
            if(cur==target_pos)return nums[cur];
            else if(cur<target_pos){
                lo=cur+1;
            }else{
                hi=cur-1;
            }
        }
        return -1;
    }
};