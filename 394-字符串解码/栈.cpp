#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<pair<int,string>> stac;
        string base_str="";
        int times=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0'&&s[i]<='9'){
                times=0;
                
                for(int j=i;j<s.size();j++){
                    if(s[j]<'0'||s[j]>'9'){
                        i=j-1;
                        break;
                    }else{
                        times=times*10+(s[j]-'0');
                    }
                }
                

            }else if(s[i]=='['){
                stac.push({times,""});
                times=-1;
            }else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
                if(stac.empty()){
                    base_str.append(1,s[i]);
                }else{
                    stac.top().second.append(1,s[i]);
                }
            }else if(s[i]==']'){
                string current;
                for(int j=0;j<stac.top().first;j++){
                    current.append(stac.top().second);
                }
                stac.pop();
                if(stac.empty()){
                    base_str.append(current);
                }else{
                    stac.top().second.append(current);
                }
            }
        }
        return base_str;
    }
};