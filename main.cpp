#include <iostream>

struct Node {
    int data;
    struct Node *next;
};

class LinkedList {
    private:
        Node *head;
        Node *tail;
        int size;
    public:
        LinkedList() {
            head = NULL;
            tail = NULL;
            size = 0;
        }
        void add(int n) {
            Node *newNode = new Node;
            newNode -> data = n;
            newNode -> next = NULL;
            if (head == NULL) {
                head = newNode;
            } else {
                tail -> next = newNode;
            }
            tail = newNode;
            size++;
        }
        void insert(int index, int n) {
            if (index > size) {
                std::cout << "Index out of range\n";
                return;
            }
            Node *newNode = new Node;
            newNode -> data = n;
            if (index == 0) {
                newNode -> next = head;
                head = newNode;
            } else if (index == size) {
                add(n);
            } else {
                int count = 1; 
                Node *curr = head;
                while(count < index) { //index = 1
                    curr = curr -> next;
                    count++;
                }
                newNode -> next = curr -> next;
                curr -> next = newNode;
            }
            size++;
        }
        void remove(int index) {
            if (index >= size) {
                std::cout << "Index out of range\n";
                return;
            }
            Node *deletedNode;
            if (index == 0) {
                deletedNode = head;
                head = head -> next;
                if (size == 0) {
                    tail = NULL;
                }
            } else if (index == size - 1) {
                deletedNode = tail;
                Node *curr = head;
                while (curr -> next != tail) {
                    curr = curr -> next;
                }
                tail = curr;
                curr -> next = NULL;
            } else {
                int count = 1;
                Node *curr = head;
                while(count < index) {
                    curr = curr -> next;
                    count++;
                }
                deletedNode = curr -> next;
                curr -> next = deletedNode -> next;
            }
            size--;
            delete deletedNode;
            return;
        }
        Node *getHead() {
            return head;
        }
        Node *getTail() {
            return tail;
        }
        void print() {
            Node *ptr = head;
            while (ptr != NULL) {
                std::cout << ptr -> data;
                ptr = ptr -> next;
                if (ptr != NULL) {
                    std::cout << " -> ";
                }
            }
            std::cout << std::endl;
        }
};

int main () {
    LinkedList oof;
    oof.add(0);
    oof.add(1);
    oof.add(2);
    oof.add(3);
    oof.add(4);
    oof.add(5);
    oof.add(6);
    oof.print();
    return 0;
}