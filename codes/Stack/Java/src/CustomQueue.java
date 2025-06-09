public class CustomQueue {
    private int[] data;
    private static final int DEFAULT_SIZE = 10;

    int end = 0;

    public CustomQueue() {
        this(DEFAULT_SIZE);
    }

    public CustomQueue(int size) {
        this.data = new int[size];
    }

    public boolean isFull() {
        return end == data.length;
        // end is at the last index of the array
    }

    public boolean isEmpty() {
        return end == 0;
    }

    public boolean insert(int item) {
        if (isFull()) {
            return false;
        }
        data[end++] = item;
        return true;
    }

    // removing is O(1) in a queue, but we need to shift elements
    // to the left, so it becomes O(n)
    public int remove() throws Exception {
        if (isEmpty()) {
            throw new Exception("Cannot remove from an empty queue");
        }
        int removed = data[0];

        // Shift all elements to the left
        for (int i = 1; i < end; i++) {
            data[i - 1] = data[i];
        }
        end--; // Decrease the end pointer
        // Why? because one item has been removed
        return removed;
    }

    public int front() throws Exception {
        if (isEmpty()) {
            throw new Exception("No front in an empty queue");
        }
        return data[0]; // O(1) operation to get the front element
    }

    public void display() {
        for (int i = 0; i < end; i++) {
            System.out.print(data[i] + "<-");
        }
        System.out.println("END");
    }

}
