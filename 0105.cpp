#include <iostream>
#include <string>
using namespace std;

/*
一次编辑

字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 
给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。
*/

/*
思路：
    滑动窗口+双指针
    pale的邻居包括ale、ple、pae、pal （n）
    .pale, p.ale, pa.le, pal.e, pale. （n+1）
    .ale, p.le, pa.e, pal. （n）
*/

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int n = first.size();
        int m = second.size();

        int left = 0; // point to pos of first
        int right = 0; // point to pos of second
        int chance = 0; // 为1的时候就不能再left right不同了
        // 根据mn的大小关系判断属于哪种情况
        if(m==n){ // update
            for(int i=0;i<n;i++){
                if(first[i]!=second[i]){
                    chance++;
                    if(chance>1) return false;
                }
            }
        }
        else if(n == m+1){ // remove
            while(left<n && right<m){
                if(first[left]!=second[right]){
                    chance++;
                    if(chance>1) return false;
                    right--;
                }
                left++;
                right++;
            }
        }
        else if(n == m-1){ // 插入
            while(left<n && right<m){
                if(first[left]!=second[right]){
                    chance++;
                    if(chance>1) return false;
                    left--;
                }
                left++;
                right++;
            }
        }
        else{
            return false;
        }

        return true;
    }
};

int main(){
    Solution s;
    string first = "";
    string second = "p";
    cout<<s.oneEditAway(first,second)<<endl;;
    system("pause");
    return 0;
}