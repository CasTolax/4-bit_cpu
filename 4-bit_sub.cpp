#include <iostream>
#include "logic_gates.h"

using namespace std;

int main() {

    /*
     4-bit adder benzer, ancak bunu farklı kılan, her bitte kendi xor kapıları terslenir,
     daha sonra and kapısından geçerek kontrol sağlanır ve bir bitlik çıkarma işlemi gerçekleşir,
     yani sonuç aslında terslenmiştir. carry'ler zincirleme mantığını burada da bulunmaktadır ve
     sonucu carry-out ile beraber verilir yani borrow olup olmadığı kontrolüdür.
    */
    int a0,b0,a1,b1,a2,b2,a3,b3; // input
    int c_in = 1; // input

    cout << "input  a0,b0 = "; // 1 LSB
    cin >> a0 >> b0;

    cout << "input a1,b2 = "; // 2
    cin >> a1 >> b1;

    cout << "input a2,b2 = "; // 3
    cin >> a2 >> b2;

    cout << "input a3,b3 = "; // 4 MSB
    cin >> a3 >> b3;

    // b'ler terslenir / invert the b
    b0 = not_gate(b0);
    b1 = not_gate(b1);
    b2 = not_gate(b2);
    b3 = not_gate(b3);

    // 1 bit 1
   int xor1 = xor_gate(a0, b0);
   int not_xor0 = not_gate(xor1); // inverter 0
   int and1 = and_gate(c_in, not_xor0);
   int s0 = xor_gate(xor1, c_in);
   int and2 = and_gate(a0, b0);
   int c0 = or_gate(and1, and2); // carry 0

   // 1 bit 2
   int xor2 = xor_gate(a1,b1);
   int not_xor1 = not_gate(xor2); // inverter 1
   int and3 = and_gate(c0, not_xor1);
   int s1 = xor_gate(xor2, c0);
   int and4 = and_gate(a1,b1);
   int c1 = or_gate(and3,and4); // carry 1

   // 1 bit 3
   int xor3 = xor_gate(a2,b2);
   int not_xor2 = not_gate(xor3); // inverter 2
   int and5 = and_gate(c1, not_xor2);
   int s2 = xor_gate(xor3,c1);
   int and6 = and_gate(a2,b2);
   int c2 = or_gate(and5,and6); // carry 2

   // 1 bit 4
   int xor4 = xor_gate(a3,b3);
   int not_xor3 = not_gate(xor4); // inverter 3
   int and7 = and_gate(c2,not_xor3);
   int s3 = xor_gate(xor4,c2);
   int and8 = and_gate(a3,b3);
   int c_out = or_gate(and7,and8); // final carry-out

    cout << "output = " << s3 << s2 << s1 << s0; // output
    cout << "  "  << "carry-out =" << " "  << c_out; // carry out

}