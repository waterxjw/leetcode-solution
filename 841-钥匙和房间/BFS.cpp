#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int roomN=rooms.size();
        queue<int> que;
        vector<bool> visit(roomN,false);
        que.push(0);
        visit[0]=true;
        while(!que.empty()){
            int current_room=que.front();
            que.pop();
            for(int i=0;i<rooms[current_room].size();i++){
                if(!visit[rooms[current_room][i]]){
                    visit[rooms[current_room][i]]=true;
                    que.push(rooms[current_room][i]);
                }
            }
        }
        for(int i=0;i<roomN;i++){
            if(!visit[i])return false;
        }
        return true;
    }
};