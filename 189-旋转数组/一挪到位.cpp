#include<vector>
using namespace std;
/**
 * 重点在于解决套圈问题，不止整除时会套圈，不互质时都会套圈。但是非整除时的套圈没理清楚……
 * 反正检测到套圈就从下一个重新开始总是没问题的
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size=nums.size();
        k=k%size;
        if(k==0)return;
        int start=0;
        int cache=nums[0];
        int next=k;
        for(int i=0;i<size;i++){
            int temp=nums[next];
            nums[next]=cache;
            cache=temp;
            if(next==start){
                start=(start+1)%size;
                cache=nums[start];
                next=(start+k)%size;
            }else{
                next=(next+k)%size;
            }
        }
    }
};