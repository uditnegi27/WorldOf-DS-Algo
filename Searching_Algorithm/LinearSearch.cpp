#include <iostream>
using namespace std;

bool linearSearch(int arr[], int arrayLenght, int number){

    for(int i=0; i<arrayLenght; i++){
        if(arr[i] == number){
            return true;
        }
    }

    return false;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int arrayLenght = sizeof(arr)/sizeof(arr[0]);
    int search  = 5;
    if(linearSearch(arr, arrayLenght, search)){
        cout<<"yes present";
    }
    else{
        cout<<"not present";
    }
    

    return 0;
}
