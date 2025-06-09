import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{

        CircularQueue queue = new CircularQueue(5);

        queue.insert(10);
        queue.insert(20);
        queue.insert(30);
        queue.insert(40);
        queue.insert(50);

        queue.display();

        System.out.println(queue.remove());

        queue.display();

        System.out.println(queue.remove());
        queue.display();

        queue.insert(60);
        queue.insert(70);
        queue.insert(80);
        queue.insert(90);
        queue.display();

    }
}
