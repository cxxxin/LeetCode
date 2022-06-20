#include <iostream>
#include <string>
using namespace std;

/*
 IP 地址无效化

 给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。
 所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。
*/

/*
思路：
    开辟多一个string
*/

class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        for(char c:address){
            if(c=='.'){
                ans.append("[.]");
            }
            else{
                ans.push_back(c);
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}