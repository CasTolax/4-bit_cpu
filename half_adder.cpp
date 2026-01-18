#include <iostream>
#include "logic_gates.h"
using namespace std;

int main() {
    int a,b; 

    cout << "input a,b = ";
    cin >> a >> b; // input a,b

    /*Toplama işlemi / adder process
    örnek/example; a = 1, b = 0 sum+carry = 10*/

    int sum = xor_gate(a,b);
    int carry = and_gate(a,b);

    cout << "output = "<< sum << carry << endl; // output
    
}