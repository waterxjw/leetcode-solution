#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
       
        queue<pair<int,int>> queue;
        for(int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    ans++;
                    queue.push({i,j});
                    grid[i][j]='0';
                    while (!queue.empty()){
                        int row=queue.front().first;
                        int column=queue.front().second;
                        if(row>0&&grid[row-1][column]=='1'){
                           
                            grid[row-1][column]='0';
                            queue.push({row-1,column});
                        }
                        if(row<grid.size()-1&&grid[row+1][column]=='1'){
                            grid[row+1][column]='0';
                            queue.push({row+1,column});
                        }
                        if(column>0&&grid[row][column-1]=='1'){
                            queue.push({row,column-1});
                            grid[row][column-1]='0';
                        }
                        if(column<grid[0].size()-1&&grid[row][column+1]=='1'){
                            queue.push({row,column+1});
                            grid[row][column+1]='0';
                        }
                        queue.pop();
                    }
                }
            }
        }
        return ans;
    }
};