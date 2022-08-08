import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

/**
 * 761. 特殊的二进制序列
 * 思路：当作是括号对、进行递归
 */

public class SolutionFor761 {
    public String makeLargestSpecial(String s) {
        if (s.length() == 0) { // the length of s is 0
            return "";
        }

        List<String> list = new ArrayList<>(); // 存储若干互不重叠的子串
        int count = 0, last = 0; // last表示上一次截断的位置
        for (int i = 0, cur = 0; i < s.length(); i++, cur++) {
            if (s.charAt(i) == '1') { // 遇到左括号
                count++;
            } else { // 遇到右括号
                count--;
            }
            //一组有效的括号匹配 去掉括号进行 内部排序
            if (count == 0) { // 凑成了n对，可以分割
                String str = "1" + makeLargestSpecial(s.substring(last + 1, cur)) + "0"; // 掐掉头尾的1和0，对中间的子串重新组合
                list.add(str);
                last = cur + 1;
            }
        }
        //进行排序，根据冒泡排序，交换两个相邻的元素进行排序，总能让内部的括号由大到小排列
        list.sort(Comparator.reverseOrder());
        //拼成完整的字符串
        StringBuilder sb = new StringBuilder();
        for (String str : list) {
            sb.append(str);
        }
        return sb.toString();
    }
}
