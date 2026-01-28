#include <iostream>
#include "logic_gates.h"
using namespace std;

struct Gates_out { // gate line 

    int not_;
    int and_;
    int or_;
    int xor_;
    int nand_;

};

struct SR_FPFP{ // SR-LACTH flip-flop line

    int a0,a1,a2,a3;
    int b0,b1,b2,b3;
    
    int q0,q1,q2,q3;
    int nq0,nq1,nq2,nq3;

    int q_new0,nq_new0;
    int q_new1,nq_new1;
    int q_new2,nq_new2;
    int q_new3,nq_new3;
};

/*struct MUX_PROCESS__ { // MUX bus line
        int d0,d1,d2,d3;
        int not0,not1,not2,not3;
        int and0,and1,and2,and3;
        int result_d0,result_d1,result_d2,result_d3;
};
*/

Gates_out gates_ctrl(int a, int b) { // gates 

    Gates_out o;

    o.not_  = not_gate(a);
    o.and_  = and_gate(a,b);
    o.or_   = or_gate(a,b);
    o.xor_  = xor_gate(a,b);
    o.nand_ = nand_gate(a,b);

    return o;
}

//SR_LATCH flip-flop
SR_FPFP Sr_FpFp(int a0, int a1, int a2, int a3, int b0, int b1, int b2, int b3, 
               int q0, int q1,int q2,int q3, int nq0, int nq1, int nq2, int nq3,
                int q_new0,int nq_new0, int q_new1,int nq_new1, int q_new2,int nq_new2,
                int q_new3, int nq_new3 ){ 

    SR_FPFP s;

    // 1 bit 0
    s.nq0 = !q0;
    s.q_new0 = nand_gate(a0,nq0);
    s.nq_new0 = nand_gate(b0,q0);
    q0 = q_new0;
    nq0 = nq_new0;

    // 1 bit 1
    s.nq1 = !q1;
    s.q_new1 = nand_gate(a1,nq1);
    s.nq_new1 = nand_gate(b1,q1);
    q1 = q_new1;
    nq1 = nq_new1;
    
    // 1 bit 2
    s.nq2 = !q2;
    s.q_new2 = nand_gate(a2,nq2);
    s.nq_new2 = nand_gate(b2,q2);
    q2 = q_new2;
    nq2 = nq_new2;
                
    // 1 bit 3
    s.nq3 = !q3;
    s.q_new3 = nand_gate(a3,nq3);
    s.nq_new3 = nand_gate(b3,q3);
    q3 = q_new3;
    nq3 = nq_new3;
    
    return s;

}

/*// 4-bit MUX --
MUX_PROCESS__ MUX(int d0, int d1,int d2,int d3,
                int not0, int not1, int not2, int not3,
                int and0, int and1, int and2, int and3,
                int s, int s1,int s2,int s3,
                int result0,int result1){ 

    MUX_PROCESS__ m;

    m.not0 = not_gate(s);
    m.not1 = not_gate(s1);
    m.not2 = not_gate(s2);
    m.not3 = not_gate(s3);

    m.and0 = and_gate(d0,d1);
    m.and1 = and_gate(d2,d3);

    m.and2 = and_gate(d0,s);
    m.and2 = and_gate(d1,s1);
    m.and2 = and_gate(d2,s2);
    m.and2 = and_gate(d3,s3);

    m.result_d0 = or_gate(and0,and1); // output
    m.result_d1 = or_gate(and2,and3);

    return m;    
}
    */

// adder
int adder_pros(int a_0, int a_1,int a_2, int a_3,
               int b_0,int b_1,int b_2, int b_3, int c_in_ADD ){

    cout << "input  a0,b0,c_in = "; // 1 LSB
    cin >> a_0 >> b_0 >> c_in_ADD;

    cout << "input a1,b2 = "; // 2
    cin >> a_1 >> b_1;

    cout << "input a2,b2 = "; // 3
    cin >> a_2 >> b_2;

    cout << "input a3,b3 = "; // 4 MSB
    cin >> a_3 >> b_3;
            
    // PROCESS
    int xor1 = xor_gate(a_0,b_0);
    int and1 = and_gate(c_in_ADD,xor1);
    int s0_a = xor_gate(xor1,c_in_ADD); // s0
    int and2 = and_gate(a_0,b_0);
    int c0 = or_gate(and1,and2);  // carry 0

    // 1 bit 2
    int xor2 = xor_gate(a_1,b_1);
    int and3 = and_gate(c0,xor2);
    int s1_a = xor_gate(xor2,c0); // s1
    int and4 = and_gate(a_1,b_1);
    int c1 = or_gate(and3,and4); // carry 1

    // 1 bit 3
    int xor4 = xor_gate(a_2,b_2);
    int and5 = and_gate(c1,xor4);
    int s2_a = xor_gate(xor4,c1); // s2
    int and6 = and_gate(a_2,b_2);
    int c2 = or_gate(and5,and6); // carry 2
    
    // 1 bit 4
    int xor6 = xor_gate(a_3,b_3);
    int and7 = and_gate(c2,xor6);
    int s3_a = xor_gate(c2,xor6); // s3
    int and8 = and_gate(a_3,b_3);
    int c_out = or_gate(and7,and8); // final carry-out

    cout << "output = " << s3_a << s2_a << s1_a << s0_a; // output
    cout << "  "  << "carry-out =" << " "  << c_out << "\n"; // carry out

    return 0;

    
}

// subtraction
int sub_pros(int ab_0,int ab_1,int ab_2,int ab_3,
    int bb_0,int bb_1,int bb_2,int bb_3){

        int c_in_SUB = 1;


        cout << "input  a0,b0 = "; // 1 LSB
    cin >> ab_0 >> bb_0;

    cout << "input a1,b2 = "; // 2
    cin >> ab_1 >> bb_1;

    cout << "input a2,b2 = "; // 3
    cin >> ab_2 >> bb_2;

    cout << "input a3,b3 = "; // 4 MSB
    cin >> ab_3 >> bb_3;

        // b'ler terslenir / invert the b
    bb_0 = not_gate(bb_0);
    bb_1 = not_gate(bb_1);
    bb_2 = not_gate(bb_2);
    bb_3 = not_gate(bb_3);

    // 1 bit 1
   int xor1 = xor_gate(ab_0, bb_0);
   int not_xor0 = not_gate(xor1); // inverter 0
   int and1 = and_gate(c_in_SUB, not_xor0);
   int s0_b = xor_gate(xor1, c_in_SUB);
   int and2 = and_gate(ab_0, bb_0);
   int c0 = or_gate(and1, and2); // carry 0

   // 1 bit 2
   int xor2 = xor_gate(ab_1,bb_1);
   int not_xor1 = not_gate(xor2); // inverter 1
   int and3 = and_gate(c0, not_xor1);
   int s1_b = xor_gate(xor2, c0);
   int and4 = and_gate(ab_1,bb_1);
   int c1 = or_gate(and3,and4); // carry 1

   // 1 bit 3
   int xor3 = xor_gate(ab_2,bb_2);
   int not_xor2 = not_gate(xor3); // inverter 2
   int and5 = and_gate(c1, not_xor2);
   int s2_b = xor_gate(xor3,c1);
   int and6 = and_gate(ab_2,bb_2);
   int c2 = or_gate(and5,and6); // carry 2

   // 1 bit 4
   int xor4 = xor_gate(ab_3,bb_3);
   int not_xor3 = not_gate(xor4); // inverter 3
   int and7 = and_gate(c2,not_xor3);
   int s3_b = xor_gate(xor4,c2);
   int and8 = and_gate(ab_3,bb_3);
   int c_out = or_gate(and7,and8); // final carry-out

   cout << "output = " << s3_b << s2_b << s1_b << s0_b; // output
    cout << "  "  << "carry-out =" << " "  << c_out << "\n"; // carry out

   return 0;

}



int main(){

         
    // ADDER OUT/INPUT
    cout << "ADDER PROCESS" << "\n";
    adder_pros(0,0,0,0,0,0,0,0,0); // adder

    // SUB OUT/INPUT
    cout << "SUB PROCESS" << "\n";
    sub_pros(0,0,0,0,0,0,0,0); // sub


    // gates_ctrl OUT------------------
    cout << "GATE CONTROL" << "\n";

    int a,b;
    cout << "input a,b = ";
    cin >> a >> b;

    Gates_out g = gates_ctrl(a,b);
    std::cout << "not out = " << g.not_<< endl;
    std::cout << "and out = " << g.and_ << endl;
    std::cout << "or out = " << g.or_<< endl;
    std::cout << "xor out = " << g.xor_ << endl;
    std::cout << "nand out = " << g.nand_ << "\n" << endl;

    //MUX OUT ----------------------
    


    // FLİP-FLOP OUT ---------------
    cout << "FLİP-FLOP PROCESS" << "\n";

    int a0,a1,a2,a3;
    int b0,b1,b2,b3;
    
    int q0,q1,q2,q3;
    int nq0,nq1,nq2,nq3;

    int q_new0,nq_new0;
    int q_new1,nq_new1;
    int q_new2,nq_new2;
    int q_new3,nq_new3;


    SR_FPFP s = Sr_FpFp(
        a0,a1,a2,a3,b0,b1,b2,b3,
        q0,q1,q2,q3,nq0,nq1,nq2,nq3,
        q_new0,nq_new0,q_new1,nq_new1,
        q_new2,nq_new2,q_new3,nq_new3
    );


    cout << "input data a0,b0 = ";
    cin >> a0 >> b0;

    cout << "input data a1,b1 = ";
    cin >> a1 >> b1;

    cout << "input data a2,b2 = ";
    cin >> a2 >> b2;

    cout << "input data a3,b3 = ";
    cin >> a3 >> b3;

    std::cout << "data 0 = " << q0 << endl;
    std::cout << "data 1 = " << q1 << endl;
    std::cout << "data 2 = " << q2 << endl;
    std::cout << "data 3 = " << q3 << endl << "\n";

    int ask_data;

    while(true){
        cout << "enter the adress? 1/0 =  ";
        cin >> ask_data;

        if (ask_data == 1){
            cout << "THE DATA\n";

            std::cout << "data 0 = " << q0 << endl;
            std::cout << "data 1 = " << q1 << endl;
            std::cout << "data 2 = " << q2 << endl;
            std::cout << "data 3 = " << q3 << endl << "\n";

            cout << "which data ? = 0/1/2/3 = ";
            cin >> ask_data;

            if (ask_data == 0){
                cout << "select data 1, reset data 0 = ";
                cin >> q0;
                break;
            }
            else if (ask_data == 1){
                cout << "select data 1, reset data 0 = ";
                cin >> q1;
                break;
            }
            else if (ask_data == 2){
                cout << "select data 1, reset data 0 = ";
                cin >> q2;
                break;
            }
            else if (ask_data == 3){
                cout << "select data 1, reset data 0 = ";
                cin >> q3;
                break;
            }
        }
        else{
            break;
            continue;
        }
    
    }

    return 0;

    
}
