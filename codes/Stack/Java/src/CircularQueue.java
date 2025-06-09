public class CircularQueue {
    protected int[] data;
    private static final int DEFAULT_SIZE = 10;

    protected int end = 0;
    protected int front = 0;
    protected int size = 0;

    public CircularQueue() {
        this(DEFAULT_SIZE);
    }

    public CircularQueue(int size) {
        data = new int[size];
    }

    public boolean isFull() {
        return end ==  data.length;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    // IMPORTANT
    public boolean insert(int item) {
        if (isFull()) {
            return false;
        }
        data[end] = item;
        end++;
        end = end % data.length;
        size++;
        return true;
    }

    public int remove() throws Exception {
        if (isEmpty()) {
            throw new Exception("Queue is empty");
        }
        int removed = data[front];
        front++;
        front = front % data.length;
        size--;
        return removed;
    }

    public int front() throws Exception {
        if (isEmpty()) {
            throw new Exception("Queue is Empty");
        }

        return data[front];

    }

    public void display() {
        int count = size;
        int i = front;
        while (count > 0) {
            System.out.print(data[i] + " -> ");
            i = (i + 1) % data.length;
            count--;
        }
        System.out.println("End");
    }
}
