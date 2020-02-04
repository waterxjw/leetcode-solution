class Solution {
public:
    vector<vector<string>> partition(string s) {
        int size=s.size();
        stack<pair<int,int>> stac;
        vector<vector<string>> ans;
        vector<string> current;
        stac.push({0,0});
        while(!stac.empty()){
            if(stac.top().second!=size-1){
                int next=stac.top().second+1;
                stac.push({next,next});
                current.push_back(s.substr(next,1));
            }else{
                //先装进ans，再回溯
            }
        }
    }
};