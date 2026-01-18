#include <iostream>
#include "logic_gates.h"
using namespace std;

int main(){
    int a0, b0, c_in; 

    cout << "a0,b0,c_in input = "; // INPUT
    cin >> a0 >> b0 >> c_in;

    
    int sum1 = xor_gate(a0,b0); // xor_gate = a0 + b0 = sum1
    int carry1 = and_gate(a0,b0); // and_gate = a0 + b0 = carry1
    int sum2 = xor_gate(sum1,c_in); // xor_gate = sum1 + c_in = sum2

    int carry2 = and_gate(sum1,c_in); // and_gate = sum1 + c_in = carry2
    int c_out = or_gate(carry1,carry2); // or_gate = carry1 + carry2 = c_out (final)

    cout << "output = " << sum2 << c_out << endl; // OUTPUT
    
}