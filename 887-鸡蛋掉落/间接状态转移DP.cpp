#include<vector>
using namespace std;
/**
 * dp[M][k]表示K个鸡蛋 最多移动M次 能最多确定的楼层高度
 * dp数组中的值不直接是结果。行坐标成了结果
 * （这谁能想得到啊）
 * 
*/
class Solution {
public:
   
    int superEggDrop(int K, int N) {
        vector<int> dp(K+1,0);
        int m=0;
        for(m=0;dp[K]<N;m++){
            //temp存储被覆盖的dp[i-1]，利用这个变量就能省下一个vector啦
            int tmp=0;
            for(int i=1;i<=K;i++){
                int tmp2=tmp;
                tmp=dp[i];
                dp[i]=tmp2+dp[i]+1;
            }
        }
        return m;
    }
};