#include<vector>
#include<queue>
using namespace std;
/**
 * 对每个点进行BFS，一次更新一个点的最短距离。很暴力
 * 冗余的地方在于各个点的BFS过程互相独立，不能相互利用，实际上做了重复的功
 * 
 * 
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        vector<vector<int>> ans(matrix);
        int rowN=matrix.size(),colN=matrix[0].size();

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int visit[10000];
                queue<int> que;
                int step=0;
                if(matrix[i][j]==0){
                    ans[i][j]=0;
                }else{
                    for(int k=0;k<rowN*colN;k++){
                        visit[k]=0;
                    }
                    que.push(i*colN+j);
                    visit[i*colN+j]=1;
                    while(!que.empty()){
                        int size=que.size();
                        step++;
                        bool isFind=false;
                        for(int k=0;k<size;k++){
                            int val=que.front();
                            int col=val%colN,row=val/colN;
                            que.pop();
                            if(row>0){
                                if(matrix[row-1][col]==0){
                                    ans[i][j]=step;
                                    isFind=true;
                                    break;
                                }else if(visit[(row-1)*colN+col]==0){
                                    visit[(row-1)*colN+col]=1;
                                    que.push((row-1)*colN+col);
                                }
                            }
                            if(row<rowN-1){
                                if(matrix[row+1][col]==0){
                                    ans[i][j]=step;
                                    isFind=true;
                                    break;
                                }else if(visit[(row+1)*colN+col]==0){
                                    visit[(row+1)*colN+col]=1;
                                    que.push((row+1)*colN+col);
                                }
                            }
                            if(col>0){
                                if(matrix[row][col-1]==0){
                                    ans[i][j]=step;
                                    isFind=true;
                                    break;
                                }else if(visit[(row)*colN+col-1]==0){
                                    visit[(row)*colN+col-1]=1;
                                    que.push((row)*colN+col-1);
                                }
                            }
                            if(col<colN-1){
                                if(matrix[row][col+1]==0){
                                    ans[i][j]=step;
                                    isFind=true;
                                    break;
                                }else if(visit[(row)*colN+col+1]==0){
                                    visit[(row)*colN+col+1]=1;
                                    que.push((row)*colN+col+1);
                                }
                            }
                        }
                        if(isFind)break;
                    }
                }
            }
        }
        return ans;
    }
};