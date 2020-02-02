#include<vector>

using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& image,int sr, int sc, int newColor){
        int rowN=image.size(),colN=image[0].size();
        int origin_color=image[sr][sc];
        image[sr][sc]=newColor;
        if(sr>=1&&image[sr-1][sc]==origin_color)dfs(image,sr-1,sc,newColor);
        if(sc>=1&&image[sr][sc-1]==origin_color)dfs(image,sr,sc-1,newColor);
        if(sr<rowN-1&&image[sr+1][sc]==origin_color)dfs(image,sr+1,sc,newColor);
        if(sc<colN-1&&image[sr][sc+1]==origin_color)dfs(image,sr,sc+1,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //当新颜色与老颜色不同时，在遍历过程中会自然的记录已遍历的点从而避免死循环。当颜色相同时直接返回好了。
        if(image[sr][sc]!=newColor){
            dfs(image,sr,sc,newColor);
        }
        
        return image;
    }
};