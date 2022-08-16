/**
 * 641. 设计循环双端队列
 * 思路：数组实现类似于循环队列，只是变成了双端
 */

public class SolutionFor641 {
    private  int[] elements;
    private int front, rear;
    private int capacity;

    public SolutionFor641(int k) {
        capacity = k+1;
        front = rear = 0;
        elements = new int[capacity];
    }

    public boolean insertFront(int value) {
        if (isFull()){
            return false;
        }

        front = (front-1+capacity) % capacity;
        elements[front] = value;
        return true;
    }

    public boolean insertLast(int value) {
        if (isFull()){
            return false;
        }

        elements[rear] = value;
        rear = (rear+1) % capacity;
        return true;
    }

    public boolean deleteFront() {
        if (isEmpty()){
            return false;
        }

        front++;
        front %= capacity;
        return true;
    }

    public boolean deleteLast() {
        if (isEmpty()){
            return false;
        }

        rear = (rear-1+capacity) % capacity;
        return true;
    }

    public int getFront() {
        if (isEmpty()){
            return -1;
        }

        return elements[front];
    }

    public int getRear() {
        if (isEmpty()){
            return -1;
        }

        return elements[(rear-1+capacity)%capacity];
    }

    public boolean isEmpty() {
        return rear==front;
    }

    public boolean isFull() {
        return (rear+1)%capacity == front;
    }
}
