#include <iostream>
using namespace std;

// Node structure to represent a term in the polynomial
struct Node {
    int coefficient;
    int exponent;
    Node* next;

    Node(int coeff, int exp) : coefficient(coeff), exponent(exp), next(nullptr) {}
};

// Function to add two polynomials represented as linked lists
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;
    Node* current = nullptr;

    while (poly1 != nullptr || poly2 != nullptr) {
        int coeff1 = (poly1 != nullptr) ? poly1->coefficient : 0;
        int exp1 = (poly1 != nullptr) ? poly1->exponent : 0;
        int coeff2 = (poly2 != nullptr) ? poly2->coefficient : 0;
        int exp2 = (poly2 != nullptr) ? poly2->exponent : 0;

        int sumCoeff = coeff1 + coeff2;
        int sumExp = exp1;

        // Create a new node for the result
        Node* newNode = new Node(sumCoeff, sumExp);

        if (result == nullptr) {
            result = newNode;
            current = result;
        } else {
            current->next = newNode;
            current = newNode;
        }

        // Move to the next term in each polynomial if available
        if (poly1 != nullptr) poly1 = poly1->next;
        if (poly2 != nullptr) poly2 = poly2->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(Node* poly) {
    while (poly != nullptr) {
        cout << poly->coefficient << "x^" << poly->exponent;
        poly = poly->next;
        if (poly != nullptr) {
            cout << " + ";
        }
    }
    cout << endl;
}

int main() {
    // Example polynomials: 3x^2 + 2x + 1 and 2x^3 - x^2 + 4
    Node* poly1 = new Node(3, 2);
    poly1->next = new Node(2, 1);
    poly1->next->next = new Node(1, 0);

    Node* poly2 = new Node(2, 3);
    poly2->next = new Node(-1, 2);
    poly2->next->next = new Node(4, 0);

    cout << "Polynomial 1: ";
    displayPolynomial(poly1);

    cout << "Polynomial 2: ";
    displayPolynomial(poly2);

    Node* result = addPolynomials(poly1, poly2);

    cout << "Sum: ";
    displayPolynomial(result);

    // Clean up memory
    delete poly1;
    delete poly2;
    delete result;

    return 0;
}
