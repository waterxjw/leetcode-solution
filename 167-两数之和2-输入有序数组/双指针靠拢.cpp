#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo=0,hi=numbers.size()-1;
        while(lo<hi){
            if(numbers[lo]+numbers[hi]==target){
                break;
            }else if(numbers[lo]+numbers[hi]<target){
                lo++;
            }else{
                hi--;
            }
        }
        vector<int> ans={lo+1,hi+1};
        return ans;
    }
};