#include <iostream>
#include <stack>
#include <string>
using namespace std;


void insertAtBottom(stack<int> &sd, int value){

    if(sd.empty()){
        sd.push(value);
        return;
    }

    int num = sd.top();
    sd.pop();

    insertAtBottom(sd, value);

    sd.push(num);
}

void ReverseStack(stack<int> &s){

    if(s.empty()){
        return;
    }

    int num = s.top();
    s.pop();

    ReverseStack(s);

    insertAtBottom(s, num);

}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.top()<<endl;
    ReverseStack(st);
    cout<<st.top()<<endl;
   
    return 0;
}