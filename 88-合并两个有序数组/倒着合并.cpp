#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int current1=m-1,current2=n-1,current=m+n-1;
        while(current!=-1){
            if(current1!=-1&&current2!=-1){
                if(nums1[current1]>nums2[current2]){
                    nums1[current]=nums1[current1];
                    current1--;
                    current--;
                }else{
                    nums1[current]=nums2[current2];
                    current2--;
                    current--;
                }
            }else if(current1!=-1){
                break;
            }else{
                nums1[current]=nums2[current2];
                current2--;
                current--;
            }
        }
    }
};