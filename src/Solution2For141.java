import java.util.HashSet;
import java.util.Set;

/**
 * 141. 环形链表
 * 思路：快慢指针
 */

public class Solution2For141 {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null)
            return false;

        ListNode slow = head, fast = head.next;
        while (slow != fast){
            if (fast == null || fast.next == null) // 快指针没有进入环  直接到结尾了
                return false;

            slow = slow.next;
            fast = fast.next.next;
        }
        return true;
    }
}
