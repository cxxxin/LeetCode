/**
 * 25. K 个一组翻转链表
 * 思路：按顺序遍历 递归
 */

public class SolutionFor25 {
    public ListNode reverseKGroup(ListNode head, int k) {
        // 递归出口
        int cnt = 0;
        ListNode curr = head;
        while (curr != null){
            curr = curr.next;
            cnt++;
        }
        if (cnt < k)
            return head;

        // 翻转
        curr = head;
        cnt = 0;
        ListNode next, prev = null;
        while (cnt < k){
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        head.next = reverseKGroup(curr, k);
        return prev;
    }
}
