#include<iostream>
using namespace std;

void insertionSort(int arr[], int size){
    for(int i =0 ;i<size;i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    for(int i =0; i<size;i++){
         cout<<"Enter element "<<(i+1)<<" :";
         cin>>arr[i];
    }
    insertionSort(arr,size);
    cout<<"The sorted array: ";
    for(int i = 0; i< size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}