#include<iostream>
using namespace std;

int linearSearch(int arr[],int size, int target){
    for(int i = 0;i < size;i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    int size;
    cout<<"Enter the size of the array";
    cin>> size;

    int* arr = new int[size];
    cout<<"Enter the element of the array:"<<endl;
    for(int i = 0;i < size; i++){
        cout<<"Element "<<i+1<<":";
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the target value to search: ";
    cin>>target;

    int result = linearSearch(arr,size,target);
    if(result != -1)
        cout<<"Element "<<target<<" found at index "<<result<<endl;
    else
        cout<<"Element "<<target<<" not found";

return 0;
}