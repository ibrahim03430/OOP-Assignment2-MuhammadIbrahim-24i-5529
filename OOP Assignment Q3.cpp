#include <iostream>
using namespace std;

class Node {
public:
    int BookID;
    string Title;
    string Author;
    Node* next;
    Node* prev;

    Node(int id, string t, string a) {
        BookID = id;
        Title = t;
        Author = a;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    void addAtBeginning(int id, string title, string author) {
        Node* newNode = new Node(id, title, author);
        if (head == NULL) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void addAtEnd(int id, string title, string author) {
        Node* newNode = new Node(id, title, author);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void addAtPosition(int pos, int id, string title, string author) {
        if (pos <= 1 || head == NULL) {
            addAtBeginning(id, title, author);
            return;
        }

        Node* newNode = new Node(id, title, author);
        Node* temp = head;
        int count = 1;

        while (temp->next != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        newNode->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteByID(int id) {
        if (head == NULL) return;

        if (head->BookID == id) {
            Node* temp = head;
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->BookID != id) {
            temp = temp->next;
        }

        if (temp == NULL) return;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        if (temp->prev != NULL)
            temp->prev->next = temp->next;

        delete temp;
    }

    void displayForward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << "Book ID: " << temp->BookID << " | Title: " << temp->Title
                << " | Author: " << temp->Author << endl;
            temp = temp->next;
        }
    }

    void displayBackward() {
        if (head == NULL) return;
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        while (temp != NULL) {
            cout << "Book ID: " << temp->BookID << " | Title: " << temp->Title
                << " | Author: " << temp->Author << endl;
            temp = temp->prev;
        }
    }

    ~DoublyLinkedList() {
        Node* temp = head;
        while (temp != NULL) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    DoublyLinkedList library;

    library.addAtEnd(1, "The Alchemist", "Paulo Coelho");
    library.addAtEnd(2, "1984", "George Orwell");
    library.addAtEnd(3, "Moby Dick", "Herman Melville");

    cout << "Books in Forward Order:" << endl;
    library.displayForward();

    cout << "\nAdding Book at Beginning..." << endl;
    library.addAtBeginning(0, "Hamlet", "William Shakespeare");
    library.displayForward();

    cout << "\nAdding Book at Position 3..." << endl;
    library.addAtPosition(3, 10, "Inferno", "Dan Brown");
    library.displayForward();

    cout << "\nDeleting Book with ID 2..." << endl;
    library.deleteByID(2);
    library.displayForward();

    cout << "\nBooks in Reverse Order:" << endl;
    library.displayBackward();

    return 0;
}
