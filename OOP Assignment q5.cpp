#include <iostream>
using namespace std;

class ArrayStack {
public:
    int* arr;
    int top;
    int capacity;

    ArrayStack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        top--;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void display() {
        cout << "Array Stack: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~ArrayStack() {
        delete[] arr;
    }
};


class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class LinkedListStack {
public:
    Node* top;

    LinkedListStack() {
        top = NULL;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        cout << "Linked List Stack: ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedListStack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};


int main() {
    ArrayStack arrStack(5);
    LinkedListStack listStack;

    cout << "Using Array-Based Stack:" << endl;
    arrStack.push(10);
    arrStack.push(20);
    arrStack.push(30);
    arrStack.display();
    arrStack.pop();
    arrStack.display();

    cout << "\nUsing Linked List-Based Stack:" << endl;
    listStack.push(1);
    listStack.push(2);
    listStack.push(3);
    listStack.display();
    listStack.pop();
    listStack.display();

    return 0;
}
