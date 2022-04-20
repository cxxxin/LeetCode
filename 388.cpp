#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
文件的最长绝对路径
*/

/*
思路：
    遍历
*/

class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        int pos = 0;
        int ans = 0;
        vector<int> level(n + 1); // 遍历到每个字母时，属于第几层目录

        while (pos < n) { // 从头开始遍历字符串
            /* 检测当前文件的深度 */
            int depth = 1;
            while (pos < n && input[pos] == '\t') { // 有一个制表符就往下一层
                pos++;
                depth++;
            }

            /* 统计当前文件名的长度 */   
            int len = 0; 
            bool isFile = false;     
            while (pos < n && input[pos] != '\n') { // 不是换行符也不是制表符，说明这里开始是个dir/文件名了
                if (input[pos] == '.') { // 出现.说明这里就是个文件了，该结算了mark一下
                    isFile = true;
                }
                len++;
                pos++;
            }

            /* 跳过换行符  也就是遇上换行符的话就不管吧*/
            pos++;

            if (depth > 1) { // 不是根目录的话一律加个/
                len += level[depth - 1] + 1;
            }
            if (isFile) { // 是文件的话就可以结算了
                ans = max(ans, len);
            } else {
                level[depth] = len; // 还是目录的话就更新一下这一层的总长度，覆盖也ok因为文件是紧跟在它属于的上级目录之后的
            }
        }
        return ans;
    }
};


int main(){
    return 0;
}