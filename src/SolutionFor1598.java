/**
 * 1598. 文件夹操作日志搜集器
 * 思路：直接模拟
 */

public class SolutionFor1598 {
    class Solution {
        public int minOperations(String[] logs) {
            int depth = 0;
            for (String log:logs){
                if ("./".equals(log)){
                    continue;
                }
                if ("../".equals(log)){
                    if (depth>0){
                        depth--;
                    }
                }
                else{
                    depth++;
                }
            }
            return depth;
        }
    }
}
