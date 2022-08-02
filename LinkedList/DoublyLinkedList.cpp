#include <iostream>
using namespace std;

class node{
    public:

    int data;
    node* prev;
    node* next;
    

    node(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* newNode = new node(val);

    newNode->next = head;
    if(head != NULL){
        head->prev = newNode;
    }

    head = newNode;
}

void insertAtTail(node* &head, int val){

    if(head == NULL){
        insertAtHead(head, val);
        return;
    } 

    node* newNode = new node(val);
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAtHead(node* &head){

    if(head == NULL) return;

    node* toDelete = head;

    head = head->next;
    head->next->prev = NULL;
    delete toDelete;

}

void deleteAtTail(node* &head){
    node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    node* toDelete = temp->next;
    temp->next = NULL;
    delete toDelete;

}

void deleteAtPosition(node* &head, int pos){
    node* temp = head;
    int count = 1;
    while(count != pos){
        temp = temp->next;
        count++;
    }

    node* toDelete = temp;
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;

    delete toDelete;

}

void display(node* head){
    while(head != NULL){
        cout<<head->data<<" -> ";
        head = head->next;
    }
}

int main(){
    node* head = NULL;
    insertAtHead(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    deleteAtHead(head);
    deleteAtTail(head);
    deleteAtPosition(head,3);
    display(head);

    return 0;
}