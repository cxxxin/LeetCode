#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

/*
统计打字方案数
*/

/*
可以记录一下算过的东西
*/

class Solution {
public:
    unordered_map<char,int> mp = { // <button,types>
        {'2',3},
        {'3',3},
        {'4',3},
        {'5',3},
        {'6',3},
        {'7',4},
        {'8',3},
        {'9',4}
    };
    unordered_map<int,long long> record3 = {
        {1,1},
        {2,2},
        {3,4}
    }; // <count,types>
    unordered_map<int,long long> record4 = {
        {1,1},
        {2,2},
        {3,4},
        {4,8}
    }; // <count,types>
    
    long long countTypes(int count, int maxLen){
        long long ans = 0;
        if(maxLen == 3){
            if(record3.count(count)) return record3[count];
            for(int i=1;i<=maxLen;i++){
                ans += countTypes(count-i,maxLen);
            }
            record3[count] = ans % int(pow(10,9) + 7);
        }
        else{
            if(record4.count(count)) return record4[count] ;
            for(int i=1;i<=maxLen;i++){
                ans += countTypes(count-i,maxLen);
            }
            record4[count] = ans % int(pow(10,9) + 7);
        }

        return ans % int(pow(10,9) + 7);
    }

    int countTexts(string pressedKeys) {
        long long ans = 1;
        int n = pressedKeys.size();
        int count = 0;
        int head = 0;
        for(int i=0;i<=n;i++){
            if((i==0 || pressedKeys[i]==pressedKeys[i-1]) && i<n);
            else{ // 歧义结束 结算
                count = i-head;
                ans *= countTypes(count, mp[pressedKeys[i-1]]);
                ans %= int(pow(10,9) + 7);
                head = i;
            }
        }

        return ans % int(pow(10,9) + 7);
    }
};

int main(){
    Solution s;
    string exp = "88888888888888888888888888888999999999999999999999999999994444444444444444444444444444488888888888888888888888888888555555555555555555555555555556666666666666666666666666666666666666666666666666666666666222222222222222222222222222226666666666666666666666666666699999999999999999999999999999888888888888888888888888888885555555555555555555555555555577777777777777777777777777777444444444444444444444444444444444444444444444444444444444433333333333333333333333333333555555555555555555555555555556666666666666666666666666666644444444444444444444444444444999999999999999999999999999996666666666666666666666666666655555555555555555555555555555444444444444444444444444444448888888888888888888888888888855555555555555555555555555555555555555555555555555555555555555555555555555555555555999999999999999555555555555555555555555555554444444444444444444444444444444555";
    cout<<s.countTexts(exp)<<endl;
    system("pause");
    return 0;
}