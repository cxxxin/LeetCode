<<<<<<< HEAD
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
最长公共前缀
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        int num = strs.size();
        int* length = new int [num];
        for(int i=0;i<num;i++){
            length[i] = strs[i].size();
        }
        int minlen = *min_element(length,length+num);
        
        for(int i=0;i<minlen;i++){
            //comparison
            bool mark = true;
            for(int j = 1;j<num;j++){
                if(strs[j][i]!=strs[0][i]){
                    mark = false;
                    break;
                }
            }
            if (mark == true){
                ans += strs[0][i];
            }
            else{
                break;
            }
        }
        delete [] length;
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> example = {"flower","flow","flight"};
    string result = s.longestCommonPrefix(example);
    cout<<result<<endl;
    system("pause");
    return 0;
=======
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
最长公共前缀
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        int num = strs.size();
        int* length = new int [num];
        for(int i=0;i<num;i++){
            length[i] = strs[i].size();
        }
        int minlen = *min_element(length,length+num);
        
        for(int i=0;i<minlen;i++){
            //comparison
            bool mark = true;
            for(int j = 1;j<num;j++){
                if(strs[j][i]!=strs[0][i]){
                    mark = false;
                    break;
                }
            }
            if (mark == true){
                ans += strs[0][i];
            }
            else{
                break;
            }
        }
        delete [] length;
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> example = {"flower","flow","flight"};
    string result = s.longestCommonPrefix(example);
    cout<<result<<endl;
    system("pause");
    return 0;
>>>>>>> 509105f88ace325a2a3d6f93e4a7a42955bea93f
}