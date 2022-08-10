#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    
    string str = "uditnegi";

    stack<int> st;

    for(int i=0; i<str.length(); i++){
        st.push(str[i]);
    }

    string reversed = "";
    while(!st.empty()){
        // tt += st.top();
        reversed.push_back(st.top());
        st.pop();
    }

    cout<<reversed;
    
    return 0; 
}