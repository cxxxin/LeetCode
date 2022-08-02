/**
 * 622. 设计循环队列
 *
 * 思路：
 * 设置一个front指针一个rear指针即可，只使用capacity-1的存储空间
 * 队列为空：front=rear
 * 队列为满：front = (rear+1) mod capacity
 */


public class SolutionFor622 {
    private int front; // head
    private int rear; // tail
    private int[] elements;
    private int capacity;

    public SolutionFor622(int k) {  // init
        capacity = k+1;
        elements = new int[k+1];
        rear = front = 0;
    }

    public boolean enQueue(int value) {
        if (isFull())
            return false;
        elements[rear] = value;
        rear++;
        rear = rear%capacity;
        return true;
    }

    public boolean deQueue() {
        if (isEmpty())
            return false;
        front++;
        front = front%capacity;
        return true;
    }

    public int Front() {
        if (isEmpty())
            return -1;
        return elements[front];
    }

    public int Rear() {
        if (isEmpty())
            return -1;
        return elements[(rear+capacity-1)%capacity];
    }

    public boolean isEmpty() {
        return rear==front;
    }

    public boolean isFull() {
        return front == ((rear+1) % capacity);
    }
}
