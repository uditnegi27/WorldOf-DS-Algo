#include <iostream>
#include <stack>
#include <string>
using namespace std;


void removeMidElement(stack<int>& st, int count, int size){
    if(count == size/2){
        st.pop();
        return;
    }

    int num = st.top();
    st.pop();

    removeMidElement(st, count+1, size);

    st.push(num);
}

int main(){

    int coun = 0;
    stack<int> sd;
    sd.push(1);
    sd.push(2);
    sd.push(3);
    sd.push(4);
    sd.push(5);
    sd.push(6);
    sd.push(7);

    cout<<sd.top()<<endl;

    removeMidElement(sd, coun, sd.size());
    cout<<sd.top()<<endl;
    sd.pop();
    cout<<sd.top()<<endl;
    sd.pop();
    cout<<sd.top()<<endl;
    sd.pop();
    cout<<sd.top()<<endl;

    return 0;
}