#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
重新排列日志文件

给你一个日志数组 logs。每条日志都是以空格分隔的字串，其第一个字为字母与数字混合的 标识符 。

有两种不同类型的日志：

字母日志：除标识符之外，所有字均由小写字母组成
数字日志：除标识符之外，所有字均由数字组成
请按下述规则将日志重新排序：

所有 字母日志 都排在 数字日志 之前。
字母日志 在内容不同时，忽略标识符后，按内容字母顺序排序；在内容相同时，按标识符排序。
数字日志 应该保留原来的相对顺序。
返回日志的最终顺序。
*/

/*
思路：
    自定义排序
*/

// 自定义一个比较器
bool myCmp(const string& log1, const string& log2){
    // 先判断是数字还是字母型
    int pos1 = log1.find_first_of(" ");
    int pos2 = log2.find_first_of(" ");
    bool isDigit1 = isdigit(log1[pos1+1]);
    bool isDigit2 = isdigit(log2[pos2+1]);
    // 都是数字，则按原来的索引返回
    if(isDigit1&&isDigit2)
        return false; // stable_Sort 用的是归并排序，所以啥也不用动

    // 有一方是字母，一方是数字，则字母在先
    if(isDigit1&&!isDigit2 || !isDigit1&&isDigit2)
        return isDigit1?false:true;
    // 都是字母
    string s1 = log1.substr(pos1+1);
    string s2 = log2.substr(pos2+1);
    // 后面的部分是否相同，相同则比较标识符
    return s1==s2?log1<log2:s1<s2;
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(),logs.end(),myCmp); // stable_sort()可以对vector的某个成员进行排序
        return logs;
    }
};

int main(){
    return 0;
}