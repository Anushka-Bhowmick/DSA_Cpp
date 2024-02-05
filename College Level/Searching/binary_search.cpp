#include<iostream>
using namespace std;

int binarySearch(int arr[],int size, int key){
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start)/2;

    while (start <= end){
        if(arr[mid] == key)
            return mid;
        
        if(arr[mid] > key)
            end = mid - 1;
        
        if(arr[mid] < key)
            start = mid + 1;
        
        mid = start + (end - start)/2;
    }
    return -1;
}

int main(){
    int size,key;
    cout<<"Enter the size of the array: ";
    cin>> size;

     int* arr = new int[size];
    for(int i = 0; i<size; i++){
        cout<<"Enter element "<<i+1<<":";
        cin>>arr[i];
    }

    cout<<"Enter the element to be searched: ";
    cin>>key;

    int result = binarySearch(arr,size,key);

    if(result != -1)
    cout<<"Element found at index: "<< result <<endl;
    else
    cout<<"Element not found!";
    return 0;
}