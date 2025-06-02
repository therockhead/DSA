template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T value) {
        data = value;
        next = nullptr;
    }
};