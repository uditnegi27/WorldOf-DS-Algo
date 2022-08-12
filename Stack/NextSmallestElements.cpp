#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> NextSmallestElements(vector<int> &vec, int len) {

    stack<int> sd;
    sd.push(-1);
    vector<int> newVec(len);

    for(int i=len-1; i>=0; i--) {
        int curr = vec[i];
        while(sd.top() >= curr){
            sd.pop();
        }
        newVec[i] = sd.top();
        sd.push(curr);
    }
    return newVec;
}

int main(){
    vector<int>  v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    vector<int> nv = NextSmallestElements(v, v.size());
    for(int i = 0; i < nv.size(); i++){
        cout<<nv[i]<<endl;
    }
    
    
    return 0;
}