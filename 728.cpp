#include <iostream>
#include <vector>

using namespace std;

/*
自除数

自除数 是指可以被它包含的每一位数整除的数。

例如，128 是一个 自除数 ，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
自除数 不允许包含 0 。

给定两个整数 left 和 right ，返回一个列表，列表的元素是范围 [left, right] 内所有的 自除数 。
*/

/*
思路：
    就按顺序遍历，但是可以剪枝：
    10的倍数都不要了；
    中间带0的也不要了；
*/

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++)
        {
            if (i % 10 == 0)
            {
                continue;
            }
            
            bool temp = true;
            int copy = i;
            while (copy != 0)
            {
                if (copy % 10 == 0 || i % (copy % 10) != 0)
                {
                    temp = false;
                    break;
                }
                
                copy /= 10;
            }

            if (temp)
            {
                ans.push_back(i);
            }      
        }
        
        return ans;
    }
};

int main(){
    return 0;
}