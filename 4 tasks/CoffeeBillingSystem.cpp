#include <iostream>
using namespace std;

int main() {
    float espressoPrice = 300, lattePrice = 350, cappuccinoPrice = 400;
    float *pEspressoPrice = &espressoPrice, *pLattePrice = &lattePrice, *pCappuccinoPrice = &cappuccinoPrice;

    int espressoQty, latteQty, cappuccinoQty;
    int *pEspressoQty = &espressoQty, *pLatteQty = &latteQty, *pCappuccinoQty = &cappuccinoQty;

    cout << "Enter quantity of Espresso: ";
    cin >> *pEspressoQty;
    cout << "Enter quantity of Latte: ";
    cin >> *pLatteQty;
    cout << "Enter quantity of Cappuccino: ";
    cin >> *pCappuccinoQty;

    float espressoTotal = (*pEspressoQty) * (*pEspressoPrice);
    float latteTotal = (*pLatteQty) * (*pLattePrice);
    float cappuccinoTotal = (*pCappuccinoQty) * (*pCappuccinoPrice);

    float totalBill;
    float *pTotalBill = &totalBill;
    *pTotalBill = espressoTotal + latteTotal + cappuccinoTotal;

    cout << "\n--- Pointer Café Bill ---\n";
    cout << "Item\t\tQty\tPrice\tSubtotal\n";
    cout << "Espresso\t" << *pEspressoQty << "\t" << *pEspressoPrice << "\t" << espressoTotal << endl;
    cout << "Latte\t\t" << *pLatteQty << "\t" << *pLattePrice << "\t" << latteTotal << endl;
    cout << "Cappuccino\t" << *pCappuccinoQty << "\t" << *pCappuccinoPrice << "\t" << cappuccinoTotal << endl;
    cout << "-------------------------------\n";
    cout << "Total Bill:\t\t\t" << *pTotalBill << endl;

    return 0;
}
