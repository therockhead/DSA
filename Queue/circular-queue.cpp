// C++ program for insertion and
// deletion in Circular Queue
#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;        
    int front, size; 
    int capacity;    

public:
  
    // Constructor to initialize the queue
    Queue(int c) {
        arr = new int[c];
        capacity = c;
        size = 0;
        front = 0;
    }

    // Get the front element
    int getFront() {
      
        // Queue is empty
        if (size == 0) 
            return -1; 
        return arr[front];
    }

    // Get the rear element
    int getRear() {
      
        // Queue is empty
        if (size == 0) 
            return -1; 
        int rear = (front + size - 1) % capacity;
        return arr[rear];
    }

    // Insert an element at the rear
    void enqueue(int x) {
      
        // Queue is full
        if (size == capacity) 
            return; 
        int rear = (front + size) % capacity;
        arr[rear] = x;
        size++;
    }

    // Remove an element from the front
    int dequeue() {
      
        // Queue is empty
        if (size == 0) 
            return -1;
        int res = arr[front];
        front = (front + 1) % capacity;
        size--;
        return res;
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
    
        int index = front;
        for (int i = 0; i < size; i++) {
            cout << arr[index] << " ";
            index = (index + 1) % capacity; // Move to the next index in a circular manner
        }
        cout << endl;
    }
};

int main() {
    Queue q(4);
    q.enqueue(10);
    cout << q.getFront() << " " << q.getRear() << endl;
    q.enqueue(20);
    cout << q.getFront() << " " << q.getRear() << endl;
    q.enqueue(30);
    cout << q.getFront() << " " << q.getRear() << endl;
    q.enqueue(40);
    cout << q.getFront() << " " << q.getRear() << endl;
    q.dequeue();
    cout << q.getFront() << " " << q.getRear() << endl;
    q.dequeue();
    cout << q.getFront() << " " << q.getRear() << endl;
    q.enqueue(50);
    cout << q.getFront() << " " << q.getRear() << endl;
   
    return 0;
}