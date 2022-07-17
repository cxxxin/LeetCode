#include <iostream>
#include <vector>
using namespace std;

/*
565. 数组嵌套

索引从0开始长度为N的数组A，包含0到N - 1的所有整数。找到最大的集合S并返回其大小，
其中 S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }且遵守以下的规则。

假设选择索引为i的元素A[i]为S的第一个元素，S的下一个元素应该是A[A[i]]，之后是A[A[A[i]]]... 以此类推，不断添加直到S出现重复的元素。
*/

/*
思路：
    模拟
    首先构造一张图，我们找到节点数最大的环即可
    由于元素的大小是在[0,n-1]内的，我们可以通过将值设为n来表示某个节点被访问过
*/

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i=0;i<n;i++){ // 从不同的节点开始
            int cnt = 0;
            while(nums[i]<n){
                int num = nums[i];
                nums[i] = n;
                i = num;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

int main(){
    return 0;
}