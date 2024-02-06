#include <iostream>
using namespace std;

int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;

    int arr[size];
    cout<<"Enter the elements in the array: ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    int max = arr[0], min = arr[0];
    for(int i = 0; i < size; i++){
        if(arr[i]>max)
        max = arr[i];
        if(arr[i]<min)
        min = arr[i];
    }

    cout<<"Maximum element: "<<max<<endl;
    cout<<"Minimum Element: "<<min<<endl;

    return 0;
}