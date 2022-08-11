import java.util.Arrays;

/**
 * 1417. 重新格式化字符串
 * 思路：用双指针进行模拟
 */

public class SolutionFor1417 {
    public String reformat(String s) {
        int n = s.length();
        int countDigit = 0;
        for (int i=0;i<n;i++){
            char c = s.charAt(i);
            if (Character.isDigit(c)){
                countDigit++;
            }
        }
        int countAlpha = n-countDigit;
        if (Math.abs(countAlpha-countDigit) >1){ // 无法构成合法的字符串
            return "";
        }

        boolean flag = countDigit > countAlpha; // 是否是数字更多，数字更多则偶数位放数字
        char[] arr = s.toCharArray();
        for (int i=0,j=1;i<n;i+=2){ // ij是双指针，一个希望指到数字，一个希望指到字母
            if (Character.isDigit(arr[i]) != flag){ // 当前的字母不在该在的位置上
                while (Character.isDigit(arr[j]) != flag){
                    j += 2;
                }
                // swap
                char c = arr[i];
                arr[i] = arr[j];
                arr[j] = c;
            }
        }

        return new String(arr);
    }
}
