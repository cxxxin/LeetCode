#include <iostream>
#include <vector>
using namespace std;

/*
复写零

给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。
注意：请不要在超过该数组长度的位置写入元素。
要求：请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。
*/

/*
思路：
    开辟一个副本
*/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> cp(n);
        cp.assign(arr.begin(),arr.end());
        int p = 0; // pointer of copy
        for(int i=0;i<n;i++){
            if(cp[p]==0){
                arr[i] = 0;
                arr[++i] = 0;
            }
            else{
                arr[i] = cp[p];
            }
            p++;
        }
    }
};

int main(){
    return 0;
}