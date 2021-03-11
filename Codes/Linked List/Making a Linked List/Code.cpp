#include <iostream>

using namespace std;


struct Node {
    int data;
    Node* next;
};

void addElem(int x, Node* h) {
    
    cout << "Adding element " << x << " to LL \n";
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    h->next = temp;
    
}

Node* makeLinkedList(int arr[], int size) {
    
    
    Node *head = new Node();
    head->data = arr[0];
    head->next = NULL;
    
     Node *curr = new Node();
     curr = head;
    
    int i = 1;
    while(head && i<size) {
        
        cout << "On Iteration i = " << i << "\n";
        addElem(arr[i], curr);
        curr = curr->next;
        i++;
    }
    return head;
    
}

void printLinkedList (Node *head) {
    
    cout << "Printing Linked List\n";
    while(head) {
        cout << head->data << " ";
        head = head -> next;
    }
}

int main() {
    int arr[5] ={1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    Node *h = makeLinkedList(arr, size);
    printLinkedList(h);
}