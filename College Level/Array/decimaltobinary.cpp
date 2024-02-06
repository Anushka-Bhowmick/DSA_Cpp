#include <iostream>
using namespace std;

void decimalToBinary(int decimalNumber, int binaryArray[], int &binarySize) {
    // Convert decimal to binary
    while (decimalNumber > 0) {
        binaryArray[binarySize] = decimalNumber % 2;
        decimalNumber /= 2;
        binarySize++;
    }
}

int main() {
    int decimalNumber;
    
    // Input the decimal number
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    // Array to store binary representation
    int binaryArray[32]; // Assuming 32-bit integer
    int binarySize = 0;

    // Function call to convert decimal to binary
    decimalToBinary(decimalNumber, binaryArray, binarySize);

    // Display the binary representation
    cout << "Binary representation: ";
    for (int i = binarySize - 1; i >= 0; i--) {
        cout << binaryArray[i];
    }

    return 0;
}
