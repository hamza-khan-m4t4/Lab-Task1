#include <iostream>
using namespace std;

int generateCode(int n) {
    if (n == 0) return 1;
    int product = 1;
    for (int i = n; i >= 1; i--) {
        product *= i;
    }
    return product;
}

int main() {
    int num;
    int (*codePtr)(int);
    codePtr = generateCode;

    cout << "Enter a number: ";
    cin >> num;

    int secretCode = codePtr(num);
    cout << "Your secret code is: " << secretCode << endl;

    return 0;
}
