#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


/*
唯一摩尔斯密码词

国际摩尔斯密码定义一种标准编码方式，将每个字母对应于一个由一系列点和短线组成的字符串， 比如:

'a' 对应 ".-" ，
'b' 对应 "-..." ，
'c' 对应 "-.-." ，以此类推。

为了方便，所有 26 个英文字母的摩尔斯密码表如下：

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
"-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

给你一个字符串数组 words ，每个单词可以写成每个字母对应摩尔斯密码的组合。

例如，"cab" 可以写成 "-.-..--..." ，(即 "-.-." + ".-" + "-..." 字符串的结合)。我们将这样一个连接过程称作 单词翻译 。
对 words 中所有单词进行单词翻译，返回不同 单词翻译 的数量。
*/

/*
思路：
    模拟+哈希？
*/

const static string MORSE[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
        "....", "..", ".---", "-.-", ".-..", "--", "-.",
        "---", ".--.", "--.-", ".-.", "...", "-", "..-",
        "...-", ".--", "-..-", "-.--", "--.."
};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> record;
        for (string s:words)
        {
            string code;
            for (char c:s){
                code.append(MORSE[c-'a']);
            }
            record.emplace(code);
        }
        return record.size();
    }
};

int main(){
    return 0;
}