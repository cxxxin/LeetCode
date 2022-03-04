#include <iostream>
#include "stdlib.h"
#include <string>
#include <vector>

using namespace std;

/*Z字形变换*/

class Solution {
public:
    string convert(string s, int numRows) {
        string result="";

        if(s.size()<=numRows|numRows==1){
            result = s;
            return result;
        }
        //动态分配n个string
        string* que;
        que = new string[numRows];

        //确定每组的元素个数
        int n = numRows*2-2;

        //遍历字符串
        for(int i=0;i<s.size();i++){
            int pos = i%n;
            if(pos>=numRows){//需要重新确定位置
                pos = n-pos;
            }
            que[pos].append(s.substr(i,1));
        }

        //按顺序赋给result
        for(int r=0;r<numRows;r++){
            result.append(que[r]);
        }

        delete []que;
        return result;
    }
};

int main(){
    Solution s;
    string result = s.convert("AB",1);
    cout<<result<<endl;
    system("pause");
    return 0;
}