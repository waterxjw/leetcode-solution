#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo=0,hi=height.size()-1;
        int ans=0;
        while(lo<hi){
            int cur=min(height[lo],height[hi])*(hi-lo);
            if(cur>ans)ans=cur;
            if(height[lo]>height[hi]){
                hi--;
            }else{
                lo++;
            }
        }
        return ans;
    }
};