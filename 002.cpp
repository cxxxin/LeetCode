#include <iostream>
#include "stdlib.h"
#include <vector>

using namespace std;

/*004*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0;
        int m = nums1.size();
        int n = nums2.size();

        int pos1=0,pos2 = 0;
        if((m+n)%2==1){
            int pos = (m+n+1)/2;

            for(int count = 0;count<pos-1;count++){
                // 到达边界
                if (pos1>=m){
                    pos2++;
                    continue;
                }
                if (pos2>=n){
                    pos1++;
                    continue;
                }
                if(nums1[pos1]<=nums2[pos2]){
                    pos1++;
                }
                else{
                    pos2++;
                }
            }
            // 最后一次比较
            if(pos1>=m){
                result = nums2[pos2];
                return result;
            }
            if(pos2>=n){
                result = nums1[pos1];
                return result;
            }
            if(nums1[pos1]<=nums2[pos2]){
                result = nums1[pos1];
                return result;
            }
            else{
                result = nums2[pos2];
                return result;
            }
        }
        else{
            int pos = (m+n)/2;
            
            for(int count=0;count<pos-1;count++){
                // 到达边界
                if (pos1>=m){
                    pos2++;
                    continue;
                }
                if (pos2>=n){
                    pos1++;
                    continue;
                }
                if(nums1[pos1]<=nums2[pos2]){
                    pos1++;
                }
                else{
                    pos2++;
                }
            }

            for(int count=0;count<2;count++){
                // 到达边界
                if (pos1>=m){
                    result += nums2[pos2];
                    pos2++;
                    continue;
                }
                if (pos2>=n){
                    result += nums1[pos1];
                    pos1++;
                    continue;
                }
                if(nums1[pos1]<=nums2[pos2]){
                    result += nums1[pos1];
                    pos1++;
                }
                else{
                    result += nums2[pos2];
                    pos2++;
                }
            }

            result = double(result) / double(2);
            return result;
        }

        return result;
    }
};

int main(){
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    Solution s;
    int result = s.findMedianSortedArrays(nums1,nums2);
    cout<<result<<endl;
    system("pause");
    return 0;
}