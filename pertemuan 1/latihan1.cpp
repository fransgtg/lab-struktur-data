#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 5
int stack[MAX];
int top = -1;

// Push function
void push (int value) {
    if (top == MAX - 1) {
        cout << "Stack penuh!" << endl;
    } else {
        top++;
        stack[top] = value;
        cout << value << " ditambahkan ke stack." << endl;
    }
}

// Pop function
void pop() {
    if (top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "\n" << stack[top] << " dihapus dari stack." << endl;
        top--;
    }
}

// Display function
void display() {
    if (top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "\nIsi stack: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        // cout << endl;
    }
}

int main() {
    system("cls");
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    // display();
    while (top != -1) {
        display();
        pop();
    }
    display();
}