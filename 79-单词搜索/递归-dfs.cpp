#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word,int row,int col,int word_index){
        if(word_index==word.size()-1)return true;
        char target=word[word_index+1];
        char tmp=board[row][col];
        board[row][col]=-1;
        if(row>=1&&board[row-1][col]==target&&dfs(board,word,row-1,col,word_index+1))return true;
        if(col>=1&&board[row][col-1]==target&&dfs(board,word,row,col-1,word_index+1))return true;
        if(row<board.size()-1&&board[row+1][col]==target&&dfs(board,word,row+1,col,word_index+1))return true;
        if(col<board[0].size()-1&&board[row][col+1]==target&&dfs(board,word,row,col+1,word_index+1))return true;
        board[row][col]=tmp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        char first_target=word[0];
        if(board.size()==0)return false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==first_target&&dfs(board,word,i,j,0))return true;
            }
        }
        return false;
    }
};