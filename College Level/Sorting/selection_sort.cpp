#include<iostream>
using namespace std;
void selectionSort(int arr[], int size){
    for(int i = 0; i <=size-2;i++){
        int min = i;
        for(int j =i; j<=size-1;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        cout<<"Enter element "<<(i+1)<<": ";
        cin>>arr[i];
    }
    selectionSort(arr,n);
    cout<<"The sorted array: ";
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}