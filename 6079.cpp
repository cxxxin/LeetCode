#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

/*
价格减免
*/

/*
思路：
    滑动窗口
*/

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        vector<string> newSentence;
        newSentence.reserve(sentence.size()/5);
        int head = 0;
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' ' || i==sentence.size()-1){ // new word
                string newWord = i==sentence.size()-1?sentence.substr(head,i-head+1):sentence.substr(head,i-head);
                // price?
                if(newWord[0] == '$' && newWord.size()>1){
                    bool isPrice = true;
                    for(int i=1;i<newWord.size();i++){
                        if(newWord[i]>'9' || newWord[i] < '0'){
                            isPrice = false;
                            break;
                        }
                    }
                    if(isPrice){
                        long double price = stoll(newWord.substr(1));
                        price *= 100-discount;
                        price /= 100;
                        price = round(price*100)/100;
                        // conovert to string
                        newWord = "$";
                        string temp = newWord;
                        newWord.append(to_string(price));
                        for(int j=0;j<newWord.size();j++){
                            if(newWord[j] == '.'){
                                temp = newWord.substr(0,j+3);
                                break;
                            }
                        }
                        newWord.swap(temp);
                    }
                }
                newSentence.push_back(newWord);
                head = i+1;
            }
        }

        // convert to string
        sentence.clear();
        sentence.append(newSentence[0]);
        for(int i=1;i<newSentence.size();i++){
            sentence.append(" ");
            sentence.append(newSentence[i]);
        }
        return sentence;
    }
};

int main(){
    return 0;
}