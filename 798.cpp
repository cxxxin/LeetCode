#include <iostream>
#include <vector>

using namespace std;

/*
得分最高的最小轮调

给你一个数组 nums，我们可以将它按一个非负整数 k 进行轮调，
这样可以使数组变为 [nums[k], nums[k + 1], ... nums[nums.length - 1], nums[0], nums[1], ..., nums[k-1]] 的形式。
此后，任何值小于或等于其索引的项都可以记作一分。

例如，数组为 nums = [2,4,1,3,0]，我们按 k = 2 进行轮调后，它将变成 [1,3,0,2,4]。
这将记为 3 分，因为 1 > 0 [不计分]、3 > 1 [不计分]、0 <= 2 [计 1 分]、2 <= 3 [计 1 分]，4 <= 4 [计 1 分]。
在所有可能的轮调中，返回我们所能得到的最高分数对应的轮调下标 k 。如果有多个答案，返回满足条件的最小的下标 k 。

*/

/*
思路：
    首先，只能遍历所有情况。
    但是存在【可重复利用的信息】，不用每次都重新加
    具体来说，可以利用差分的思想，比如给定的值是3，那么我们知道目标坐标从3到n-1都可以加1分
*/

class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n+1);

        for(int i=0;i<n;i++){
            if(nums[i]<n){ // 当前元素在索引范围内
                int start = nums[i];
                int end = n-1;

                // 分类讨论了要
                if(i<start){ // 不用分两段
                    start = i+n-start;
                    end = i+n-end;
                    diff[end]++;
                    diff[start+1]--;
                }
                else{
                    start = i-start;
                    diff[0]++;
                    diff[start+1]--;
                    start = i+1;
                    start = i+n-start;
                    end = i+n-end;
                    diff[end]++;
                    diff[start+1]--;
                }
            }
        }

        int ans = 0;
        int count = diff[0];
        for(int i=1;i<n;i++){
            diff[i] += diff[i-1];
            if(diff[i]>count){
                count = diff[i];
                ans = i;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> exp = {2,3,4,1,0};
    Solution s;
    s.bestRotation(exp);
    system("pause");
    return 0;
}