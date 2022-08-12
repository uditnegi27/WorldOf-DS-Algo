#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> PriviousSmallestElements(vector<int> & vec, int len) {
    
    stack<int> sd;
    sd.push(-1);
    vector<int> newvec(len);

    for(int i=0; i < len; i++){
        while(sd.top() >= vec[i]){
            sd.pop();
        }
        newvec[i] = sd.top();
        sd.push(vec[i]);
    }

    return newvec;
}

int main(){
    vector<int>  v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    vector<int> nv = PriviousSmallestElements(v, v.size());

    for(int i = 0; i < nv.size(); i++){
        cout<<nv[i]<<endl;
    }
    
    
    return 0;
}