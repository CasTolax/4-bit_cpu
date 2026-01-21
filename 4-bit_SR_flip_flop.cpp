#include <iostream>
#include "logic_gates.h"

using namespace std;

int main() {
    //---------------------------------
    int a0; // input
    int b0;
    int q0; // sr-latch choose

    // 1 bit 0

    cout << "input a0,b0 = ";
    cin >> a0 >> b0;

    cout << "input q0 = ";
    cin >> q0;

     int nq0 = !q0; // 11 X / 01-10-00 OK

    int q_new0 = nand_gate(a0,nq0); // flip-flop
    int nq_new0 = nand_gate(b0,q0);

    q0 = q_new0;
    nq0 = nq_new0;
 
    //---------------------------------
    // 1 bit 1

    int a1; 
    int b1;
    int q1; 

    cout << "input a1,b1 = ";
    cin >> a1 >> b1;

    cout << "input q1 = ";
    cin >> q1;

     int nq1 = !q1; // 11 X / 01-10-00 OK

    int q_new1 = nand_gate(a1,nq1); // flip-flop
    int nq_new1 = nand_gate(b1,q1);

    q1 = q_new1;
    nq1 = nq_new1;

    //---------------------------------
    int a2; 
    int b2;
    int q2; 

    // 1 bit 2

    cout << "input a2,b2 = ";
    cin >> a2 >> b2;

    cout << "input q2 = ";
    cin >> q2;

     int nq2 = !q2; // 11 X / 01-10-00 OK

    int q_new2 = nand_gate(a2,nq2); // flip-flop
    int nq_new2 = nand_gate(b2,q2);

    q2 = q_new2;
    nq2 = nq_new2;

    //---------------------------------

    int a3; 
    int b3;
    int q3; 

    // 1 bit 3

    cout << "input a3,b3 = ";
    cin >> a3 >> b3;

    cout << "input q3 = ";
    cin >> q3;

     int nq3 = !q3; // 11 X / 01-10-00 OK

    int q_new3 = nand_gate(a3,nq3); // flip-flop
    int nq_new3 = nand_gate(b3,q3);

    q3 = q_new3;
    nq3 = nq_new3;

    cout << "bit 1 = " << "| q0 = " << q0 << " " << "| nq0 = " << nq0 << "\n";

    cout << "bit 2 = " << "| q1 = " << q1 <<  " " << "| nq1 = " << nq1 << "\n";

    cout << "bit 3 = " << "| q2 = " << q2 << " " << "| nq2 = " << nq2 << "\n";

    cout << "bit 4 = " << "| q3 = " << q3 << " " << "| nq3 = " << nq3 << "\n";

}