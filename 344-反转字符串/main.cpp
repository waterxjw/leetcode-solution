#include<vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        int size=s.size();
        for(int i=0;i<=((int)(size/2))-1;i++){
            temp=s[i];
            s[i]=s[size-1-i];
            s[size-1-i]=temp;
        }
    }
};