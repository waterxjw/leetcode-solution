#include<vector>
#include<iostream>
using namespace std;
class UnionSet {
private:
    vector<int> parent;
    int count = 0;
public:
    UnionSet(vector<vector<char>>& grid) {
        if (grid.size() == 0)return;
        int row = grid.size(), column = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (grid[i][j] == '0') {
                    parent.push_back(-1);
                }
                else {
                    parent.push_back(i*column + j);
                    count++;
                }
            }
        }
    }
    int find(int index) {
        if (parent[index] == -1 || parent[index] == index)return parent[index];
        parent[index] = find(parent[index]);
        return parent[index];
    }
    void Union(int a, int b) {
        int roota = find(a), rootb = find(b);
        if(roota!=rootb){
            parent[roota] = rootb;
            count--;
        }

    }
    int get_count() { return count; }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        UnionSet unionset(grid);
        if (grid.size() == 0)return 0;
        int rowNum = grid.size(), columnNum = grid[0].size();
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < columnNum; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    if (i >= 1 && grid[i - 1][j] == '1') {
                        unionset.Union(i*columnNum + j, (i - 1)*columnNum + j);
                    }
                    if (i <= rowNum - 2 && grid[i + 1][j] == '1') {
                        unionset.Union(i*columnNum + j, (i + 1)*columnNum + j);
                    }
                    if (j >= 1 && grid[i][j - 1] == '1') {
                        unionset.Union(i*columnNum + j, i*columnNum + j - 1);
                    }
                    if (j <= columnNum - 2 && grid[i][j + 1] == '1') {
                        unionset.Union(i*columnNum + j, (i)*columnNum + j + 1);
                    }
                }
            }
        }
        return unionset.get_count();
    }
};