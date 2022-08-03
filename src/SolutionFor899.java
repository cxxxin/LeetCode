import java.util.Arrays;

/**
 * 899. 有序队列
 *
 * 思路：
 * 分类讨论，当k=1的时候，只有n-1种移法，直接比较即可
 * 当k>1的时候，一定可以经过移动将 ss 变成升序字符串。
 */

public class SolutionFor899 {
    public String orderlyQueue(String s, int k) {
        if (k==1){
            String ans = s;
            StringBuilder sb = new StringBuilder(s);
            int n = s.length();
            for (int i=0;i<n;i++){
                char c = sb.charAt(0);
                sb.deleteCharAt(0);
                sb.append(c);
                if (sb.toString().compareTo(ans)<0){
                    ans = sb.toString();
                }
            }
            return ans;
        }
        else{
            char[] arr = s.toCharArray();
            Arrays.sort(arr);
            return new String(arr);
        }
    }
}
