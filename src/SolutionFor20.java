import java.util.ArrayDeque;
import java.util.Deque;

/**
 * 20. 有效的括号
 * 思路：用栈进行模拟
 */

public class SolutionFor20 {
    public boolean isValid(String s) {
        Deque<Character> stack = new ArrayDeque<>();
        for (char ch:s.toCharArray()){
            if (ch == '(' || ch == '{' || ch == '['){
                stack.addLast(ch);
            }
            else if (ch == ')'){
                if (stack.isEmpty() || stack.peekLast() != '(')
                    return false;
                stack.removeLast();
            }
            else if (ch == '}'){
                if (stack.isEmpty() || stack.peekLast() != '{')
                    return false;
                stack.removeLast();
            }
            else {
                if (stack.isEmpty() || stack.peekLast() != '[')
                    return false;
                stack.removeLast();
            }
        }

        return stack.isEmpty();
    }
}
