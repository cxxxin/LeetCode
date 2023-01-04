/**
 * 206. 反转链表
 * 思路：遍历过去
 */

public class SolutionFor206 {
    public ListNode reverseList(ListNode head) {
        ListNode pre = null;
        while (head != null){
            ListNode next = head.next;
            head.next = pre;
            if (next == null)
                return head;
            pre = head;
            head = next;
        }

        return null;
    }
}
