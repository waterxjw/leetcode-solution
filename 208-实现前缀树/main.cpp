#include<string>
using namespace std;
class Trie {
private:
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
    };
    TrieNode root;
public:
    Trie() {
        
    }
    void insert(string word) {
        TrieNode* current=&root;
        for(int i=0;i<word.size();i++){
            if(current->children[word[i]-'a']==0){
                current->children[word[i]-'a']=new TrieNode();
            }
            current=current->children[word[i]-'a'];
        }
        current->isKey=true;
    }
    bool search(string word) {
        TrieNode* current=&root;
        for(int i=0;i<word.size();i++){
            if(current->children[word[i]-'a']==0){
                return false;
            }
            current=current->children[word[i]-'a'];
        }
        return current->isKey;
    }
    bool startsWith(string word) {
        TrieNode* current=&root;
        for(int i=0;i<word.size();i++){
            if(current->children[word[i]-'a']==0){
                return false;
            }
            current=current->children[word[i]-'a'];
        }
        return true;
    }
};