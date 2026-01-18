#include <iostream> 
#include <stdio.h> 
#ifndef logic_gates.h
#define logic_gates.h
using namespace std;

/*
Not Gate; bir giriş ve bir çıkış. / an input and an output
and,or,xor,nand,nor,xnor gate; iki giriş ve bir çıkış üretir. / two input and generates an output 
*/


// all the gates
int not_gate(int a) {return (a==1) ? 0:1;}  //1 = 0 / 0 = 1

int and_gate(int a,int b) {return(a==1 && b==1) ? 1:0;} // 0,0 = 0 / 1,0 = 0 / 0,1 = 0 / 1,1 = 1

int or_gate(int a,int b) {return(a==1 || b==1) ? 1:0;} // 0,0 = 0 / 1,0 = 1 / 0,1 = 1 / 1,1 = 1

int xor_gate(int a,int b) {return(a != b) ? 1:0;} // 0,0 = 0 / 1,0 = 1 / 0,1 = 1 / 1,1 = 0

int nand_gate(int a,int b) {return not_gate(and_gate(a,b));} // 0,0 = 1 / 1,0 = 1 / 0,1 = 1 / 1,1 = 0

int nor_gate(int a,int b) {return not_gate(or_gate(a,b));} // 0,0 = 1 / 1,0 = 0 / 0,1 = 0 / 1,1 = 0

int xnor_gate(int a,int b ) {return not_gate(xor_gate(a,b));} // 0,0 = 1 / 1,0 = 0 / 0,1 = 0 / 1,1 = 1


int main(){
    //input
    int a,b;
    cout << "INPUT = ";
    cin >> a >> b;
    
    //OUTPUT
    cout << "NOT = " << not_gate(a) << endl;
    cout << "AND = " << and_gate(a, b) << endl;
    cout << "OR  = " << or_gate(a, b) << endl;
    cout << "XOR = " << xor_gate(a, b) << endl;
    cout << "NAND = " << nand_gate(a, b) << endl;
    cout << "NOR = " << nor_gate(a, b) << endl;
    cout << "XNOR = " << xnor_gate(a, b) << endl;

    return 0;


}
#endif