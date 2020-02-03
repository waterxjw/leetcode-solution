#include<vector>
using namespace std;
/**
 * 暴搜 对每个位置，遍历寻找是否有相同的
 * 先排序，再顺序遍历
 * 借用一个hash set 遍历过程中存储出现过的数以便及时对比
 * 异或！！！  对位操作的理解不深啊
 * 
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
        }
        return ans;
    }
};
