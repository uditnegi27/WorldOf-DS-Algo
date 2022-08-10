#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool coutOfOpeartionNeed(string str) {
    
    stack<char> sd;

    for(int i=0; i<str.length(); i++){
        if(str[i] == '{' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            sd.push(str[i]);
        }

        else{
            
            if(str[i] == '}'){
                bool flag = false;
                while(sd.top() != '{'){
                    if(sd.top() == '+' || sd.top() == '-' || sd.top() == '*' || sd.top() == '/'){
                        flag = false;
                    }
                    sd.pop();
                }
                if(flag == true){
                    return true;
                }
                sd.pop();
            }
        }
    } 

    return false;
}

int main(){
    string st = "{a+{b+c}}";
    if(coutOfOpeartionNeed(st)) cout<<"string is redundant";
    else cout<<"string is not redundant";

    return 0;
}