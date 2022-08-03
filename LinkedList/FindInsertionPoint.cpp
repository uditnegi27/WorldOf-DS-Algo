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

/* This function will make the intersection between two linked list */
void makeIntersection(node* &head1, node* &head2, int pos){
    node* temp = head1;
    node* inter;
    int count = 1;
    while(temp->next != NULL){
        if(count == pos){
            inter = temp;
        }
        temp = temp->next;
        count++;
    }

    node* temp2 = head2;
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }

    temp2->next = inter;
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

/* This function will return the value of the intetsection node value */
int intersectionNodeValue(node* &head1, node* &head2){

    node* temp1;
    node* temp2;

    int length_1 = lengthOfLinkedList(head1);
    int length_2 = lengthOfLinkedList(head2);

    int diff = 0;

    if(length_1 > length_2){
        temp1 = head1;
        temp2 = head2; 
        diff = length_1 - length_2;
    }
    else{
        temp1 = head2;
        temp2 = head1;
        diff = length_2 - length_1;
    }

    while(diff){
        if(temp1 == NULL){
            return -1;
        }
        temp1 = temp1->next;
        diff--;
    }

    while(temp1 != NULL && temp2 != NULL){
        if(temp1 == temp2) return temp1->data;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return -1;
}

int main(){
    node* head1 = NULL;
    insertAtHead(head1, 10);
    insertAtHead(head1, 9);
    insertAtHead(head1, 8);
    insertAtHead(head1, 7);
    insertAtHead(head1, 6);
    insertAtTail(head1, 11);
    insertAtTail(head1, 12);
    insertAtTail(head1, 13);
    insertAtTail(head1, 14);
    insertAtTail(head1, 15);
    insertAtTail(head1, 16);
    insertAtTail(head1, 17);
    insertAtTail(head1, 18);
    node* head2 = NULL;
    insertAtHead(head2, 1);
    insertAtHead(head2, 2);
    insertAtHead(head2, 3);
    makeIntersection(head1, head2, 7);
    // printLinkedList(head1);
    // cout<<endl;
    // printLinkedList(head2);
    // cout<<endl;
    // cout<<lengthOfLinkedList(head1);
    // cout<<endl;
    // cout<<lengthOfLinkedList(head2);
    cout<<intersectionNodeValue(head1, head2);

    return 0;
}
