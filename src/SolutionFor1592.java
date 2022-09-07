public class SolutionFor1592 {
    class Solution {
        public String reorderSpaces(String text) {
            StringBuilder res = new StringBuilder();
            int n = text.length();
            String[] words = text.trim().split("\\s+"); // 按照空格分割
            int cntSpace = n;
            for (String word:words){
                cntSpace -= word.length();
            }

            if (words.length==1){ // 只有一个单词
                res.append(words[0]);
                for (int i=0;i<cntSpace;i++){
                    res.append(' ');
                }
                return res.toString();
            }

            // 不只有一个单词
            int perSpace = cntSpace/(words.length-1);
            int restSpace = cntSpace % (words.length-1);
            for (int i=0;i< words.length;i++){
                if (i>0){
                    for (int j=0;j<perSpace;j++){
                        res.append(' ');
                    }
                }
                res.append(words[i]);
            }
            for (int i=0;i<restSpace;i++){
                res.append(' ');
            }
            return res.toString();
        }
    }
}
