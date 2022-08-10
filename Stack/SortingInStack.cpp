#include <iostream>
#include <stack>
#include <string>
using namespace std;

void elementSort(stack<int> &sd, int number) {
    if(sd.empty() || sd.top() > number) {
        sd.push(number);
        return;
    }

    int element = sd.top();
    sd. pop();
    elementSort(sd, element);
    sd.push(element);

}

void sortStack(stack<int> &st){

    if(st.empty()) return;

    int num = st.top();
    st.pop();

    sortStack(st);

    elementSort(st, num);

}

int main(){ 
    stack<int> st;
    st.push(5);
    st.push(1);
    st.push(6);
    st.push(2);
    st.push(7);
    st.push(4);
    
    sortStack(st);
    cout<<st.top()<<endl;
   
    return 0;
}