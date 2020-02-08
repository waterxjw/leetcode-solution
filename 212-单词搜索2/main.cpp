#include<string>
#include<vector>
using namespace std;
class TrieNode{
public:
    bool isKey;
    TrieNode* children[26];
    TrieNode(){
        isKey=false;
        for(int i=0;i<26;i++){
            children[i]=0;
        }
    }
    ~TrieNode(){
        for(int i=0;i<26;i++){
            if(children[i]!=0){
                delete(children[i]);
                children[i]=0;
            }
        }
    }
};
class Trie {
private:

    TrieNode root;
public:
    Trie() {

    }
    ~Trie(){
        delete(&root);
    }
    void insert(string word) {
        TrieNode* current=&root;
        for(int i=0;i<word.size();i++){
            if(current->children[(int)word[i]-'a']==0){
                current->children[(int)word[i]-'a']=new TrieNode();
            }
            current=current->children[(int)word[i]-'a'];
        }
        current->isKey=true;
    }
    bool search(string word) {
        TrieNode* current=&root;
        for(int i=0;i<word.size();i++){
            if(current->children[(int)word[i]-'a']==0){
                return false;
            }
            current=current->children[(int)word[i]-'a'];
        }
        return current->isKey;
    }
    bool del(string word){
        TrieNode* current=&root;
        for(int i=0;i<word.size();i++){
            if(current->children[(int)word[i]-'a']==0){
                return false;
            }
            current=current->children[(int)word[i]-'a'];
        }
        current->isKey=false;
        return true;
    }
    bool startsWith(string word) {
        TrieNode* current=&root;
        for(int i=0;i<word.size();i++){
            if(current->children[(int)word[i]-'a']==0){
                return false;
            }
            current=current->children[(int)word[i]-'a'];
        }
        return true;
    }
};
class Solution {
private:

public:
    void dfs(vector<vector<char>>& board,vector<string>& ans,Trie& trie,int row,int col,string current){
        if(trie.search(current)){
            ans.push_back(current);
            trie.del(current);
        }
        char temp=board[row][col];
        board[row][col]=-1;
        if(row>=1&&trie.startsWith(current+string(1,board[row-1][col])))dfs(board,ans,trie,row-1,col,current+string(1,board[row-1][col]));
        if(col>=1&&trie.startsWith(current+string(1,board[row][col-1])))dfs(board,ans,trie,row,col-1,current+string(1,board[row][col-1]));
        if(row<board.size()-1&&trie.startsWith(current+string(1,board[row+1][col])))dfs(board,ans,trie,row+1,col,current+string(1,board[row+1][col]));
        if(col<board[0].size()-1&&trie.startsWith(current+string(1,board[row][col+1])))dfs(board,ans,trie,row,col+1,current+string(1,board[row][col+1]));
        board[row][col]=temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(int i=0;i<words.size();i++){
            trie.insert(words[i]);
        }
        vector<string> ans;
        if(board.size()==0)return ans;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(board,ans,trie,i,j,string(1,board[i][j]));
            }
        }
        return ans;
    }
};