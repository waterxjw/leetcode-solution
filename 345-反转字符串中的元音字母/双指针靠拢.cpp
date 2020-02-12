#include<string>
using namespace std;
class Solution {

public:
    bool isVowel(char a){
        if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U')return true;
        return false;
    }
    string reverseVowels(string s) {
        int lo=0,hi=s.size()-1;
        while(true){
            for(;lo<s.size()-1;lo++){
                if(isVowel(s[lo]))break;
            }
            for(;hi>0;hi--){
                if(isVowel(s[hi]))break;
            }
            if(lo<hi){
                char temp=s[lo];
                s[lo]=s[hi];
                s[hi]=temp;
                lo++;
                hi--;
            }else{
                break;
            }
        }
        return s;
    }
};