#include<vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rowN=matrix.size(),colN=matrix[0].size();
        vector<vector<int>> dist(rowN,vector<int>(colN,INT_MAX));
        for(int i=0;i<rowN;i++){
            for(int j=0;j<colN;j++){
                if(matrix[i][j]==0){
                    dist[i][j]=0;
                }else{
                    if(i>0&&dist[i-1][j]<dist[i][j]-1)dist[i][j]=dist[i-1][j]+1;
                    if(j>0&&dist[i][j-1]<dist[i][j]-1)dist[i][j]=dist[i][j-1]+1;
                }
            }
        }
        for(int i=rowN-1;i>=0;i--){
            for(int j=colN-1;j>=0;j--){
                if(matrix[i][j]==0){
                    dist[i][j]=0;
                }else{
                    if(i<rowN-1&&dist[i+1][j]<dist[i][j]-1)dist[i][j]=dist[i+1][j]+1;
                    if(j<colN-1&&dist[i][j+1]<dist[i][j]-1)dist[i][j]=dist[i][j+1]+1;
                }
            }
        }
        return dist;
    }
};