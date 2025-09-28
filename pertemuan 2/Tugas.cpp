#include <iostream>
using namespace std;

// Node untuk linked list (menyimpan nilai dan alamat node setelahnya)
struct Node {
    int data;
    Node* next;
};

// Pointer ke top
Node* top = NULL;

// Push
void push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << value << " berhasil dimasukkan ke stack.\n";
}

// Pop
void pop() {
    if (top == NULL) {
        cout << "Stack kosong\n";
        return;
    }
    Node* temp = top;
    cout << temp->data << " dikeluarkan dari stack.\n";
    top = top->next;
    delete temp;
}

// Display
void display() {
    if (top == NULL) {
        cout << "Stack kosong!\n";
        return;
    }
    cout << "Isi stack: ";
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    system("cls");
    push(10);
    push(20);
    push(40);
    push(50);
    display();

    pop();
    display();
}