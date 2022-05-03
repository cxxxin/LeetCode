#include <iostream>
#include <vector>
using namespace std;

/*
排序数组

给你一个整数数组 nums，请你将该数组升序排列。

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
*/

/*
思路：
    可以拿来练习八大排序
*/

class Solution {
private:
    // 将两个有序的序列合并
    void merge(vector<int>& nums, int l, int mid, int r){
        // 开个数组copy原本的nums
         vector<int> cp;
         cp.assign(nums.begin()+l, nums.begin()+r+1);

         // merge
         int m = 0;
         int n = mid+1-l;
         for(int i=l;i<=r;i++){
            if(m+l>mid){
                nums[i] = cp[n];
                n++;
            }
            else if(n+l>r){
                nums[i] = cp[m];
                m++;
            }
            else{
                if(cp[m]<=cp[n]){
                    nums[i] = cp[m];
                    m++;
                }
                else{
                    nums[i] = cp[n];
                    n++;
                }
            }
         }
    }
    void mergeSort(vector<int>& nums, int l, int r){
        if(l<r){
            // 分治
            int mid = (l+r) / 2;
            mergeSort(nums,l,mid);
            mergeSort(nums,mid+1,r);
            // 合并
            merge(nums,l,mid,r);
        }
    }

    /*------------------------------------------------------*/
    void quickSort(){
        
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        this->mergeSort(nums,0,n-1);
        return nums;
    }
};

int main(){
    Solution s;
    vector<int> exp = {5,3,2,1};
    s.sortArray(exp);
    system("pause");
    return 0;
}