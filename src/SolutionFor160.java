/**
 * 160. 相交链表
 * 思路：消除两个链表的长度差
 */

public class SolutionFor160 {
    public class Solution {
        public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
            if (headA==null || headB==null)
                return null;

            ListNode left = headA, right = headB;
            while (left!=right){
                left = left==null?headB:left.next;
                right = right==null?headA:right.next;
            }
            return left;
        }
    }

}
