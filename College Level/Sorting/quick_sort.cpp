#include<iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i+1);
}

void QuickSort(int arr[], int low, int high) {
    int pi;
    if(low < high) {
        pi = partition(arr, low, high);
        QuickSort(arr, low, pi-1);
        QuickSort(arr, pi+1, high);
    }
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];

    for(int i = 0; i < size; i++) {
        cout << "Enter element " << (i+1) << " : ";
        cin >> arr[i];
    }

    QuickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);
    
    delete[] arr;

    return 0;
}
