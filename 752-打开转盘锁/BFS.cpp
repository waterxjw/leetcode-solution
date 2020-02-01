#include <vector>
#include <queue>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>> queue;
        unordered_set<string> set;
        for(int i=0;i<deadends.size();i++){
            set.insert(deadends[i]);
        }
        if(target=="0000")return 0;
        else if(set.count("0000")){
            return -1;
        }
        queue.push({"0000",0});
        set.insert("0000");
        string neighbors[8];
        while (!queue.empty()){
            string current(queue.front().first);
            int level=queue.front().second;
            queue.pop();
            listNeighbors(current,neighbors);
            for(int i=0;i<8;i++){
                if(neighbors[i]==target)return level+1;
                if(!set.count(neighbors[i])){
                    set.insert(neighbors[i]);
                    queue.push({neighbors[i],level+1});
                }
            }
        }
        return -1;
    }
    void listNeighbors(string input,string* ans){
        for(int i=0;i<4;i++){
            for(int j=0;j<2;j++){
                string current(input);
                current[i]=rotate(current[i],j);
                ans[2*i+j]=current;
            }
        }
    }
    char rotate(char c, bool direction){
        if(direction){
            if(c=='9')return '0';
            char ans(c+1);
            return ans;
        } else{
            if(c=='0')return '9';
            char ans(c-1);
            return ans;
        }
    }
    
};