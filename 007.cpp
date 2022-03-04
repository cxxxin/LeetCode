#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

/*整数反转*/

class Solution {
public:
    int reverse(int x) {

        int result = 0;

        if(x>=0){
            int i = 0;
            while(x>0){
                int pre = result;
                result = result*10+x%10;
                if((result - (x%10))/10 != pre){
                    return 0;
                }
                x /= 10;
            }
        }
        else{
            int i = 0;
            x = -x;
            while(x>0){
                int pre = result;
                result = result*10-x%10;
                if((result + (x%10))/10 != pre){
                    return 0;
                }
                x /= 10;
            }
        }

        return result;
    }
};

int main(){
    Solution s;
    int result = s.reverse(1534236469);
    cout<<result<<endl;
    system("pause");
    return 0;
}