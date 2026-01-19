#include <iostream>
#include "logic_gates.h"
using namespace std;

int main(){
    int a,b,b_in;

    cin >> a >> b >> b_in;

    int diff_0 = xor_gate(a,b);
    int not_borr = not_gate(a);
    int borr0 = and_gate(not_borr,b);

    int diff_1 = xor_gate(diff_0,b_in);
    int not_b_in = not_gate(diff_0);
    int borr2 = and_gate(not_b_in,b_in);
    
    int b_out = or_gate(borr2,borr0);

    cout << "output = " << diff_1 << borr2 << endl;

}