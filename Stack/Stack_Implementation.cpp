#include <iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top;

    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else{
            cout<<"stack is overflow"<<endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout<<"stack is underflow"<<endl;
        }
    }

    int peek(){
        if(top >= 0){
            return arr[top];
        }
        else{
            cout<<"stack is empty";
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){

    Stack st(5);
    st.push(22);
    st.push(44);
    st.push(55);
    cout<<st.peek();

    return 0;
}