import java.util.PriorityQueue;

public class SolutionFor23 {
    // 自定义的比较器
    class Status implements Comparable<Status> {
        int val;
        ListNode ptr;

        Status(int val, ListNode ptr) {
            this.val = val;
            this.ptr = ptr;
        }

        public int compareTo(Status status2) {
            return this.val - status2.val;
        }
    }

    PriorityQueue<Status> queue = new PriorityQueue<>();
    public ListNode mergeKLists(ListNode[] lists) {
        for (ListNode node:lists){ // 将k个最小值都入队
            if (node != null) {
                queue.offer(new Status(node.val, node));
            }
        }

        ListNode head = new ListNode(0); /// 伪头部节点
        ListNode tail = head;
        while (!queue.isEmpty()){
            Status f = queue.poll(); // 最小值出队
            tail.next = f.ptr; // 获得当前节点的地址并接到答案的链子上
            tail = tail.next;
            if (f.ptr.next != null){
                queue.offer(new Status(f.ptr.next.val, f.ptr.next));
            }
        }

        return head.next;
    }
}
