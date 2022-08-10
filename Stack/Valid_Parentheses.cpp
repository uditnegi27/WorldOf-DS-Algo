#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool validParentheses(string str){
    stack<char> st;
    int index = 0;
    while(index < str.length()){
        if(str[index] == '{' || str[index] == '[' || str[index] == '('){
            st.push(str[index]);
            index++;
        }
        else if(str[index] == '}'){
            if(!st.empty() && st.top() == '{'){
                st.pop();
                index++;
            }
            else{
                return false;
            }
        }
        else if(str[index] == ']'){
            if(!st.empty() && st.top() == '['){
                st.pop();
                index++;
            }
            else{
                return false;
            }
        }
        else if(str[index] == ')'){
            if(!st.empty() && st.top() == '('){
                st.pop();
                index++;
            }
            else{
                return false;
            }
        }
    }

    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
    
}

int main(){

    string sr = "}]";

    if(validParentheses(sr)){
        cout<<"valid"<<endl;
    }
    else{
        cout<<"invalid"<<endl;
    }

    return 0;
}