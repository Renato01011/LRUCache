template <typename T>
struct Node {
        Node* next;
        Node* prev;
        T data;
        Node(T data) : data{data} {}
    };

template <typename T>
class CircularLinkedList {

private:
    
    int size = 0;

public:

    Node<T>* front;
    Node<T>* back;

    CircularLinkedList() {}

    void Insert(T data) {
        if (size == 0) {
            front = new Node<T>(data);
            front->next = front;
            front->prev = front;
            back = front;
            back->next = front;
            back->prev = front;
        }
				else if (size == 1) {
					Node<T>* new_Node = new Node<T>(data);
					front->next = new_Node;
					front->prev = new_Node;
					new_Node->prev = front;
					new_Node->next = front;
					back = new_Node;
				}
        else {
            Node<T>* new_Node = new Node<T>(data);
            back->next = new_Node;
            new_Node->prev = back;
						new_Node->next = front;
            back = new_Node;
        }
        size++;
    }

    Node<T>* Front() {
        return front;
    }

    Node<T>* Back() {
        return back;
    }

    void set_Back(Node<T>* n) {
        back = n;
    }

    void set_Front(Node<T>* n) {
        front = n;
    }

};