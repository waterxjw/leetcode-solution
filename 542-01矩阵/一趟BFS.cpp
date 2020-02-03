#include<vector>
#include<queue>
using namespace std;
/**
 * 为啥没想到呢
 * 实际上是没有想到dist[i][j]与相邻四个点的dist值的递推关系。
 * 正是因为这个递推关系，所以才可以应用类似于泛洪的思想进行BFS，去一浪一浪的更新dist值
 * 其实想到这个递推关系，进而也能想到DP
 * 
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rowN=matrix.size(),colN=matrix[0].size();
        vector<vector<int>> dist(rowN,vector<int>(colN,INT_MAX));
        queue<pair<int,int>> que;
        //先把所有的0点压入队列，作为源头开始遍历
        for(int i=0;i<rowN;i++){
            for(int j=0;j<colN;j++){
                if(matrix[i][j]==0){
                    que.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        while(!que.empty()){
            int row=que.front().first,col=que.front().second;
            que.pop();
            if(row>=1&&dist[row-1][col]>dist[row][col]+1){
                dist[row-1][col]=dist[row][col]+1;
                que.push({row-1,col});
            }
            if(col>=1&&dist[row][col-1]>dist[row][col]+1){
                dist[row][col-1]=dist[row][col]+1;
                que.push({row,col-1});
            }
            if(row<rowN-1&&dist[row+1][col]>dist[row][col]+1){
                dist[row+1][col]=dist[row][col]+1;
                que.push({row+1,col});
            }
            if(col<colN-1&&dist[row][col+1]>dist[row][col]+1){
                dist[row][col+1]=dist[row][col]+1;
                que.push({row,col+1});
            }
           
        }
        return dist;
    }
};