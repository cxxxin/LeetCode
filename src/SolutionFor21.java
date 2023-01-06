/**
 * 21. 合并两个有序链表
 * 思路：双指针
 */

public class SolutionFor21 {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode head = new ListNode(-1); // 伪头部节点
        ListNode curr = head;
        while (list1 != null && list2 != null){
            if (list1.val <= list2.val){
                curr.next = list1;
                curr = curr.next;
                list1 = list1.next;
            }
            else {
                curr.next = list2;
                curr = curr.next;
                list2 = list2.next;
            }
        }

        if (list1 != null){
            curr.next = list1;
        }

        else {
            curr.next = list2;
        }

        return head.next;
    }
}
