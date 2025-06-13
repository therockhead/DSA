public class DynamicStack extends customStack {
        public DynamicStack() {
            super(); // Calls the default constructor of customStack

        }
        public DynamicStack(int size) {
            super(size); // Calls the parameterized constructor of customStack
        }

    @Override
    public boolean push(int item) {
        if (this.isFull()) {
            //  double the array size
            int[] temp = new int[data.length * 2];

            for (int i = 0; i < data.length; i++) {
                temp[i] = data[i]; // Copy elements to the new array
            }
            data = temp; // Update the reference to the new array
        }
        // at this point, we know that the stack is not full
        // insert item
        return super.push(item);
    }
}
