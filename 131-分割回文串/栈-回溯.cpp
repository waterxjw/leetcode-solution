#include<string>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int size=s.size();
        stack<pair<int,int>> stac;
        vector<vector<string>> ans;
        vector<string> current;
        stac.push({0,0});
        current.push_back(s.substr(0,1));
        while(!stac.empty()){
            if(stac.top().second!=size-1){
                int next=stac.top().second+1;
                stac.push({next,next});
                current.push_back(s.substr(next,1));
            }else{
                //先装进ans，再回溯
                ans.push_back(current);
                current=vector<string>(current);
                while(!stac.empty()){
                    stac.pop();
                    current.pop_back();
                    if(stac.empty())break;
                    int lo=stac.top().first,hi=stac.top().second;
                    bool isBreak=false;
                    for(hi=hi+1;hi<size;hi++){
                        int i=lo,j=hi;
                        bool isP=true;
                        while(i<j){
                            if(s[i]!=s[j]){
                                isP=false;
                                break;
                            }
                            i++;
                            j--;
                        }
                        if(isP){
                            isBreak=true;
                            break;
                        }
                    }
                    if(isBreak){
                        stac.pop();
                        current.pop_back();
                        stac.push({lo,hi});
                        current.push_back(s.substr(lo,hi-lo+1));
                        break;
                    }
                }
            }
        }
        return ans;
    }
};