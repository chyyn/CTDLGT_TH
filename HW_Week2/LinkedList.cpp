#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insert(Node* head, int position, int data) {
    Node* newNode = new Node;
    newNode->data = data;

    // If inserting at the beginning
    if (position == 0 || head == nullptr) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* temp = head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

Node* deleteNode(Node* head, int position) {
    if (head == nullptr)
        return nullptr;

    Node* temp = head;

    // If deleting the head node
    if (position == 0) {
        head = head->next;
        delete temp;
    }
    else {
        Node* prev = nullptr;
        for (int i = 0; i < position; i++) {
            prev = temp;
            temp = temp->next;
            if (temp == nullptr)
                break;
        }
        if (temp != nullptr) {
            prev->next = temp->next;
            delete temp;
        }
    }

    return head;
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "insert") {
            int position, data;
            cin >> position >> data;
            head = insert(head, position, data);
        }
        else if (operation == "delete") {
            int position;
            cin >> position;
            head = deleteNode(head, position);
        }
    }

    printLinkedList(head);

    return 0;
}