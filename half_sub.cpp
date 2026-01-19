#include <iostream>
#include "logic_gates.h"
using namespace std;

int main() {
    int a,b;

    cout << "input = ";
    cin >> a >> b;

    int difference = xor_gate(a,b);
    int not_borrow = not_gate(a);
    int borrow = and_gate(not_borrow,b); 

    cout << "output = " << borrow << difference << endl;
}