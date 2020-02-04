#include<vector>
using namespace std;
/**
 * dp[K][N]
*/
class Solution {
public:
    int max(int a,int b){
        return a<b?b:a;
    }
    int min(int a,int b){
        return a<b?a:b;
    }
    int superEggDrop(int K, int N) {
        vector<int> vector1(N+1,0);
        vector<int> vector2(N+1,0);
        vector<int> &old=vector1;
        vector<int> &next=vector2;
        for(int i=0;i<=N;i++){
            old[i]=i;
        }
        for(int i=0;i<K-1;i++){
            next[0]=0;
            next[1]=1;
            for(int j=2;j<N+1;j++){
                int lo=1,hi=j;
                int mid;
                bool isEnd=false;
                while(hi>lo+1){
                    mid=(lo+hi)/2;
                    if(old[mid-1]==next[j-mid]){
                        next[j]=old[mid-1]+1;
                        isEnd=true;
                        break;
                    }else if(old[mid-1]<next[j-mid]){
                        lo=mid;
                    }else{
                        hi=mid;
                    }
                }
                if(isEnd)continue;
                next[j]=min(next[j-lo],old[hi-1])+1;
            }
            vector<int> &tmp=old;
            old=next;
            next=tmp;
        }
        return old[N];

    }
};