/**
 * 1455. 检查单词是否为句中其他单词的前缀
 * 思路：直接遍历，按顺序查找
 */

public class SolutionFor1455 {
    public int isPrefixOfWord(String sentence, String searchWord) {
        int n = sentence.length(), index = 1, start = 0, end = 0;
        while (start<n){
            while (end<n && sentence.charAt(end)!=' '){ // 找到当前单词的结尾
                end++;
            }
            // judge
            boolean judge = true;
            for (int i=0; i<searchWord.length();i++){
                if (start+i>=end || sentence.charAt(start+i)!=searchWord.charAt(i)){
                    judge = false;
                    break;
                }
            }
            if (judge)
                return index;
            index++;
            end++;
            start = end;
        }
        return -1;
    }
}
