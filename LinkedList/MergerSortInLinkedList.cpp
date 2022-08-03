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

/* This function will sort the two linked list using a merge sort concept */
node* mergeSortInLinkedList(node* &head1, node* &head2){
    node* temp1 = head1;
    node* temp2 = head2;
    node* dummyNode = new node(-1);
    node* temp3 = dummyNode;

    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data < temp2->data){
            temp3->next = temp1;
            temp1 = temp1->next;
        }
        else{
            temp3->next = temp2;
            temp2 = temp2->next;
        }
        temp3 = temp3->next;
    }

    while (temp1 != NULL)
    {
        temp3->next = temp1;
        temp1 = temp1->next;
        temp3 = temp3->next;
    }

    while (temp2 != NULL)
    {
        temp3->next = temp2;
        temp2 = temp2->next;
        temp3 = temp3->next;
    }
    
    return dummyNode->next;
}

int main(){
    node* head1 = NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 3);
    insertAtTail(head1, 5);
    insertAtTail(head1, 7);
    insertAtTail(head1, 9);
    insertAtTail(head1, 11);
    insertAtTail(head1, 13);
    insertAtTail(head1, 15);
    insertAtTail(head1, 17);
    node* head2 = NULL;
    insertAtTail(head2, 2);
    insertAtTail(head2, 4);
    insertAtTail(head2, 6);
    insertAtTail(head2, 8);
    insertAtTail(head2, 10);
    insertAtTail(head2, 12);
    insertAtTail(head2, 14);
    insertAtTail(head2, 16);
    node* newHead = mergeSortInLinkedList(head1, head2);
    printLinkedList(newHead);
    
    return 0;
}