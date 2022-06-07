#include <iostream>
#include <vector>
using namespace std;

/*
爱吃香蕉的珂珂
*/

/*
思路：
    二分查找
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for(int pile:piles){
            high = max(high,pile);
        }

        int ans = high;
        int speed = 0;
        long time = 0;
        while(low<high){
            speed = low + (high-low)/2;
            time = getTime(piles,speed);
            if(time>h){ // not enough
                low = speed+1;
            }
            else{
                ans = speed;
                high = speed;
            }
        }
        return ans;
    }

    long getTime(const vector<int>& piles, int speed){
        long time = 0;
        for(int pile:piles){
            time += (pile+speed-1)/speed;
        }
        return time;
    }
};

int main(){
    return 0;
}