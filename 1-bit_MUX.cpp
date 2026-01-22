#include <iostream>
#include "logic_gates.h"

using namespace std;

int main() {
    int d0,d1;
    int s;

    cout << "input data - d0,d1 =  ";
    cin >> d0 >> d1; // input data

    cout << "select data d0-d1 ?= ";
    cin >> s;

    int not1 = not_gate(s); // invert

    int and1 = and_gate(d0,not1);
    int and2 = and_gate(d1,s);

    int result_d = or_gate(and1,and2);

    cout << "out = " << result_d << "\n"; // out data
}