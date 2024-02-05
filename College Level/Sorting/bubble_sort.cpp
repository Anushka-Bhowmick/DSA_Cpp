#include<iostream>
using namespace std;

void bubbleSort(int arr[],int size){
    int temp = 0;
    for(int i =0;i<size;i++)
    {
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int* arr = new int[size];
    for(int i =0;i<size;i++){
        cout<<"Enter element "<<(i+1)<<": ";
        cin>>arr[i];
    }
    bubbleSort(arr,size);
    cout<<"The sorted array: ";
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}