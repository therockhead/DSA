public class customStack {
    protected int[] data;
    private static final int DEFAULT_SIZE = 10;

    int ptr = -1; // initial pointer
    public customStack() {
        this.data = new int[DEFAULT_SIZE];
    }
    public customStack(int size) {
        this.data = new int[size];
    }

    public boolean isFull() {
        return ptr == data.length -1;
        // ptr is at the last index of the array
    }

    private boolean isEmpty(){

        return ptr == -1;
    }

    public boolean push(int item) {
        if (isFull()) {
            System.out.println("Stack is full, cannot push " + item);
            return false;
        }
        ptr++; // increment pointer by 1 as we are pushing
        data[ptr] = item;
        return true;
    }
    public int pop() throws Exception {
        if(isEmpty()){
            throw new Exception("Cannot Pop From an Empty Stack");
        }
        int removed = data[ptr];
        ptr--;
        return removed;
    }
    public int peek() throws Exception {
        if(isEmpty()){
            throw new Exception("Cannot Peek From an Empty Stack");
        }
        return data[ptr];
    }
}
