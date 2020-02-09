#include<string>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        pair<int,int> arr[26];
        for(int i=0;i<26;i++){
            arr[i]={0,-1};
        }
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a'].first++;
            if(arr[s[i]-'a'].second==-1)arr[s[i]-'a'].second=i;
        }
        int ans=-1;
        for(int i=0;i<26;i++){
            if(arr[i].first==1){
                if(ans==-1){
                    ans=arr[i].second;
                }else if(arr[i].second<ans){
                    ans=arr[i].second;
                }
            }
        }
        return ans;
    }
};