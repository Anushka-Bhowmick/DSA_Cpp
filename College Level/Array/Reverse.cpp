#include<iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    int ar2[size];

    cout << "Enter the elements in the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < size; i++) {
        ar2[i] = arr[size - i - 1];
    }

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << ar2[i] << " ";
    }

    return 0;
}
