#include <iostream>
using namespace std;

bool binarySearch(int arr[], int startIndex, int lastIndex, int number){

    while(startIndex <= lastIndex){
        int mid = (startIndex+lastIndex)/2;
        if(arr[mid] == number){
            return true;
        }
        else if(number < arr[mid]){
            lastIndex = mid - 1;
        }
        else {
            startIndex = mid + 1;
        }
    }
    
    return false;
}

bool binarySearch_recursion(int arr[], int startIndex, int lastIndex, int number){

    if(startIndex <= lastIndex){
        int mid = (startIndex + lastIndex)/2;
        if(arr[mid] == number){
            return true;
        }
        else if(number < arr[mid]){
            return binarySearch_recursion(arr, startIndex, mid-1, number);
        }
        else{
            return binarySearch_recursion(arr, mid+1, lastIndex, number);
        }
    }

    return false;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int arrayLenght = sizeof(arr)/sizeof(arr[0]);
    int search_1 = 8;
    int search_2 = 4;

    if(binarySearch_recursion(arr, 0, arrayLenght, search_1)){
        cout<<"Element "<<search_1<<" is present in the array.";
    }
    else{
        cout<<"Element "<<search_1<<" is not present in the array.";
    }

    cout<<endl;

    if(binarySearch_recursion(arr, 0, arrayLenght, search_2)){
        cout<<"Element "<<search_2<<" is present in the array.";
    }
    else{
        cout<<"Element "<<search_2<<" is not present in the array.";
    }
    

    return 0;
}
