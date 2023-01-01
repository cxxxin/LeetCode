/**
 * 2351. 第一个出现两次的字母
 * 思路：遍历+记录
 */

public class SolutionFor2351 {
    public char repeatedCharacter(String s) {
        boolean[] rcd = new boolean[26];
        for (char ch:s.toCharArray()){
            if (rcd[ch-'a'])
                return ch;
            else {
                rcd[ch-'a'] = true;
            }
        }

        return '.';
    }
}
