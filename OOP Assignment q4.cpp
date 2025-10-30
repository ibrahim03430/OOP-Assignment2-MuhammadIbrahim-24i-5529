#include <iostream>
using namespace std;

class Customer {
public:
    int id;
    string name;
    int tickets;
    Customer* next;

    Customer(int i, string n, int t) {
        id = i;
        name = n;
        tickets = t;
        next = NULL;
    }
};

class Queue {
public:
    Customer* front;
    Customer* rear;

    Queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int id, string name, int tickets) {
        Customer* newCustomer = new Customer(id, name, tickets);

        if (rear == NULL) {
            front = rear = newCustomer;
            return;
        }

        rear->next = newCustomer;
        rear = newCustomer;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Customer* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        cout << "Customer " << temp->name << " (ID " << temp->id << ") served." << endl;
        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Customer* temp = front;
        cout << "Current Queue:" << endl;
        while (temp != NULL) {
            cout << "ID: " << temp->id
                << " | Name: " << temp->name
                << " | Tickets: " << temp->tickets << endl;
            temp = temp->next;
        }
    }

    ~Queue() {
        while (front != NULL) {
            Customer* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(1, "Ali", 2);
    q.enqueue(2, "Sara", 4);
    q.enqueue(3, "Ahmed", 1);

    q.display();

    cout << "\nServing first customer..." << endl;
    q.dequeue();

    cout << "\nAfter serving one customer:" << endl;
    q.display();

    cout << "\nAdding new customer..." << endl;
    q.enqueue(4, "Zain", 3);

    q.display();

    return 0;
}
