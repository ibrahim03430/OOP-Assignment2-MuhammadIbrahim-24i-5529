#include <iostream>
using namespace std;

class Feature {
public:
    string Name;
    virtual void analyze() = 0;
    virtual ~Feature() {}
};

class LandFeature : public Feature {
public:
    LandFeature(string n) { Name = n; }
    void analyze() {
        cout << "Land Feature detected: " << Name << endl;
    }
};

class WaterFeature : public Feature {
public:
    WaterFeature(string n) { Name = n; }
    void analyze() {
        cout << "Water Feature detected: " << Name << endl;
    }
};

class Node {
public:
    int FeatureID;
    Feature* feature;
    Node* next;

    Node(int id, Feature* f) {
        FeatureID = id;
        feature = f;
        next = NULL;
    }
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int featureID, Feature* f) {
        Node* newNode = new Node(featureID, f);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteByID(int featureID) {
        if (head == NULL) return;

        if (head->FeatureID == featureID) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* previous = NULL;
        while (current != NULL && current->FeatureID != featureID) {
            previous = current;
            current = current->next;
        }

        if (current == NULL) return;

        previous->next = current->next;
        delete current;
    }

    void displayAll() {
        Node* temp = head;
        while (temp != NULL) {
            cout << "Feature ID: " << temp->FeatureID << " - ";
            temp->feature->analyze();
            temp = temp->next;
        }
    }

    void reverseList() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    ~SinglyLinkedList() {
        Node* temp = head;
        while (temp != NULL) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtEnd(1, new LandFeature("Forest"));
    list.insertAtEnd(2, new WaterFeature("River"));
    list.insertAtEnd(3, new LandFeature("Desert"));
    list.insertAtEnd(4, new WaterFeature("Lake"));

    cout << "All Features:" << endl;
    list.displayAll();

    cout << "\nDeleting Feature with ID 2..." << endl;
    list.deleteByID(2);
    list.displayAll();

    cout << "\nReversing List..." << endl;
    list.reverseList();
    list.displayAll();

    return 0;
}
