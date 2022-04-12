#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
写字符串需要的行数
*/

/*
思路：
    直接遍历
*/

const int MAX_WIDTH = 100; // 换行

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int width = 0;
        for (char c : s) {
            int need = widths[c - 'a'];
            width += need;
            if (width > MAX_WIDTH) {
                lines++;
                width = need;
            }
        }
        return {lines, width};
    }
};


int main(){
    return 0;
}