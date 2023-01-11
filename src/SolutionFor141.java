import java.util.HashSet;
import java.util.Set;

/**
 * 141. 环形链表
 * 思路：使用哈希
 */

public class SolutionFor141 {
    public boolean hasCycle(ListNode head) {
        Set<ListNode> set = new HashSet<>();
        while (head != null){
            if (set.contains(head))
                return true;
            set.add(head);
            head = head.next;
        }
        return false;
    }
}
