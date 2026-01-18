#include <iostream> 
#include <stdio.h> 
#ifndef logic_gates_h
#define logic_gates_h
using namespace std;

/*
Not Gate; bir giriş ve bir çıkış. / an input and an output
and,or,xor,nand,nor,xnor gate; iki giriş ve bir çıkış üretir. / two input and generates an output 
*/


// all the gates
int not_gate(int a) {return(a==1)?0:1;} // 1 = 0 / 0 = 1

int and_gate(int a,int b){return(a==1 && b==1)?1:0;} // 0,0 = 0 / 1,0 = 0 / 0,1 = 0 / 1,1 = 1

int or_gate(int a,int b){return(a==1 || b==1)?1:0;} // 0,0 = 0 / 1,0 = 1 / 0,1 = 1 / 1,1 = 1

int xor_gate(int a,int b){return(a!=b)?1:0;} // 0,0 = 0 / 1,0 = 1 / 0,1 = 1 / 1,1 = 0

int nand_gate(int a,int b){return not_gate(and_gate(a,b));} // 0,0 = 1 / 1,0 = 1 / 0,1 = 1 / 1,1 = 0

int nor_gate(int a,int b){return not_gate(or_gate(a,b));} // 0,0 = 1 / 1,0 = 0 / 0,1 = 0 / 1,1 = 0

int xnor_gate(int a,int b ){return not_gate(xor_gate(a,b));}// 0,0 = 1 / 1,0 = 0 / 0,1 = 0 / 1,1 = 1


#endif
