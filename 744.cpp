#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
寻找比目标字母大的最小字母

给你一个排序后的字符列表 letters ，列表中只包含小写英文字母。另给出一个目标字母 target，
请你寻找在这一有序列表里比目标字母大的最小字母。

在比较时，字母是依序循环出现的。举个例子：

如果目标字母 target = 'z' 并且字符列表为 letters = ['a', 'b']，则答案返回 'a'

*/

/*
思路：
    就直接二分查找+取模？
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
         return target < letters.back() ? *upper_bound(letters.begin(), letters.end() - 1, target) : letters[0];
         //upper_bound() 函数用于在指定范围内查找大于目标值的第一个元素。
         // 比最后一个元素小的话说明不会循环到列表头，否则就返回第一个了
    }   
};

int main(){
    return 0;
}