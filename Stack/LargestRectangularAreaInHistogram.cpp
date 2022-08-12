#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> NextSmallestElements(vector<int> vec, int len) {

    stack<int> sd;
    sd.push(-1);
    vector<int> newVec(len);

    for(int i=len-1; i>=0; i--) {
        int curr = vec[i];
        while(sd.top() != -1 && vec[sd.top()] >= curr){
            sd.pop();
        }
        newVec[i] = sd.top();
        sd.push(i);
    }
    return newVec;
}

vector<int> PriviousSmallestElements(vector<int> vec, int len) {

    stack<int> sd;
    sd.push(-1);
    vector<int> newVec(len);

    for(int i=0; i < len; i++) {
        int curr = vec[i];
        while(sd.top() != -1 && vec[sd.top()] >= curr){
            sd.pop();
        }
        newVec[i] = sd.top();
        sd.push(i);
    }
    return newVec;
}

int LargestRectangularAreaInHistogram(vector<int> &vec, int len) {

    vector<int> next(len); 
    next = NextSmallestElements(vec, len);
    vector<int> prev(len); 
    prev = PriviousSmallestElements(vec, len);

    int area = INT_MIN;

    for(int i=0; i<len; i++) {
        int ln = vec[i];
        if(next[i] == -1){
            next[i] = len;
        }
        int br = next[i] - prev[i] - 1;
        int newarea = ln * br;
        area = max(area, newarea);
    }

    return area;
}

int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    int m = LargestRectangularAreaInHistogram(v, v.size());

    cout<<m;
    return 0;
}