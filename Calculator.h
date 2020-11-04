//
// Created by CH on 2020/11/2.
//

#ifndef SEQUENTIALSTACK_CALCULATOR_H
#define SEQUENTIALSTACK_CALCULATOR_H
#include <math.h>
#include "SeqStack.h"
#include <iostream>



class Calculator {
public:
Calculator(int s1,int s2):s(s1),charStack(s2){}
  void Run();
  void Clear();

public:
    SeqStack<int> s;
    SeqStack<char> charStack;
    void AddOperand(int value);
    bool get2Operands(int& left,int & right);
    void DoOperator(char op);
    int Calculate(int b,int a,char c);
    int isp(char c);
    int icp(char c);
    bool Isoperator(char c);
    char Precede(char c1,char c2);
    int DoCal();
    bool IsTopEnd(){
        char c;
        charStack.getTop(c);
        return c=='#';
    }





};


#endif //SEQUENTIALSTACK_CALCULATOR_H
