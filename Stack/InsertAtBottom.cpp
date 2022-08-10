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

int main(){
    stack<int> st;
    st.push(2);
    st.push(3);
    st.push(4);

    insertAtBottom(st, 1);

    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
   
    return 0;
}