#include <iostream>
using namespace std;

/* class to construct the node */
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

/* This function will insert the node at the head of the linked list */
void insertAtHead(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    n->next = head;
    head = n;
}

/* This function insert the node at the tail of the linked list */
void insertAtTail(node* &head, int val){
    node* n = new node(val);
    node* temp = head;
    
    if(head == NULL){
        return insertAtHead(head, val);
    }

    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;
}

/* This function will print the linked list */
void printLinkedList(node* head){
    while(head != NULL){
        cout<<head->data<<"   --->    ";
        head = head->next;
    }
}

/* This function will return the length of a linked list */
int lengthOfLinkedList(node* head){
    int count = 0;

    while( head != NULL){
        head = head->next;
        count++;
    }

    return count;
}

/* This function append the last k node of a linked list */
node* appendLastKnodes(node* &head, int k){

    node* tail = head;
    node* newTail;
    node* newHead;
    int length = lengthOfLinkedList(head);
    int count = 1;
    while(tail->next != NULL){
        if(count == (length - k)){
            newTail = tail;
        }
        if(count == (length - k + 1)){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;

    return newHead;
    
}

int main(){
    node* head = NULL;
    insertAtHead(head, 10);
    insertAtHead(head, 9);
    insertAtHead(head, 8);
    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtTail(head, 11);
    insertAtTail(head, 12);
    insertAtTail(head, 13);
    insertAtTail(head, 14);
    insertAtTail(head, 15);
    insertAtTail(head, 16);
    insertAtTail(head, 17);
    insertAtTail(head, 18);
    printLinkedList(head);
    cout<<endl;
    node* newNode = appendLastKnodes(head, 4);
    printLinkedList(newNode);

    return 0;
}