#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
迷你语法分析器

给定一个字符串 s 表示一个整数嵌套列表，实现一个解析它的语法分析器并返回解析的结果 NestedInteger 。
列表中的每个元素只可能是整数或整数嵌套列表
*/

/*
思路：
    深搜
*/

class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();
 
    // Constructor initializes a single integer.
    NestedInteger(int value);
 
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
 
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
 
    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
 };

class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s[0] != '['){ // 已经是个数了
            return NestedInteger(stoi(s));
        }

        int num = 0; // 算数
        stack<NestedInteger> record;
        bool negative = false;

        int i = 0;
        for (char c:s){
            if(c=='-'){ // 正负
                negative = true;
            }
            else if(isdigit(c)){ // 是否是数字
                num = num*10+(c-'0');
            }
            else if(c=='['){ // 是个嵌套列表
                record.emplace(NestedInteger());
            }
            else if(c==']' || c==','){ // 一个数字或列表结束
                // 前面是数字
                if(isdigit(s[i-1])){
                    if(negative){
                        num *= -1;
                    }
                    record.top().add(num); // 扩充列表
                }
                num = 0;
                negative = false; // 重新初始化

                if(c == ']' && record.size() > 1){ // 列表结束后，需要弹出栈顶的NestedInteger 实例，并赋值给更上一层
                    NestedInteger ni = record.top();
                    record.pop();
                    record.top().add(ni);
                }
            }
            i++;
        }
        return record.top();
    }
};
 
int main(){
    return 0;
}