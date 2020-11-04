//
// Created by CH on 2020/11/2.
//

#include "Calculator.h"
void Calculator::DoOperator(char op) {
    int left,right,value;
    bool result;
    result = get2Operands(left,right);
    if(result==true){
        switch (op) {

            case '+':
                value = left+right;
                s.Push(value);
                break;
            case '-':
                value = left-right;
                s.Push(value);
                break;
            case '*':
                value = left*right;
                s.Push(value);
                break;
            case '/':
                if(right==0.0){
                    cerr<<"Divide by 0!"<<endl;
                    Clear();
                }
                else{
                    value = left/right;
                    s.Push(value);
                }

                break;
        }
//cout<<"this value = "<<value<<endl;
    }
    else Clear();
}
int Calculator::Calculate(int b,int a,char c){
    switch (c) {
        case '+':
            return a+b;
        case '-':
            return b-a;
        case '/':
            return b/a;
        case '*':
            return a*b;
        default:
            break;
    }

}
bool Calculator::get2Operands(int& left,int & right){
    if(s.IsEmpty()==true){
        cerr<<"缺少右操作数"<<endl;
        return false;
    }
    s.Pop(right);
    if(s.IsEmpty()==true){
        cerr<<"缺少左操作数"<<endl;
        return false;
    }
    s.Pop(left);
    return true;


}
void Calculator::AddOperand(int value) {
    //cout<<"value = "<<value<<endl;
    s.Push(value);
}
void Calculator::Run() {
    char ch;
    double newOperand;
    while(cin>>ch,ch!='#'){
        switch (ch) {
        case '+':case '-':case '*':case '/':
            DoOperator(ch);
            break;
            default:cin.putback(ch);
            cin>>newOperand;
            AddOperand(newOperand);

        }


    }


}
void Calculator::Clear() {
    s.MakeEmpty();
}
int Calculator::isp(char c){
    switch (c) {
        case '#':
        return 0;
        case '(':
            return 1;
        case '*':case '/':case '%':
            return 5;
        case '+':case '-':
            return 3;
        case ')':
            return 6;
    }
}
int Calculator::icp(char c){
    switch (c) {
        case '#':
            return 0;
        case '(':
            return 6;
        case '*':case '/':case '%':
            return 4;
        case '+':case '-':
            return 2;
        case ')':
            return 1;
    }
}
bool Calculator::Isoperator(char c){
    switch(c){
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '#':
            return true;
            break;
        default:
            return false;
            break;
    }

}
char Calculator::Precede(char c1,char c2){
 /*   if((c1=='('&&c2=='#')||(c1==')'&&c2=='(')||(c1=='#'&&c2==')')){
        return '0';
    }*/

    int result=isp(c1)-icp(c2);
    if(result==0)
        return '=';
    else if(result<0){
        return '<';
    }
    else{
        return '>';
    }

}
int Calculator::DoCal(){
    charStack.Push('#');
    int counter=0;
    char c=getchar();
    while(c!='#'||!IsTopEnd()){
        if(!Isoperator(c)){
            if(counter==1){
                int t;
                s.Pop(t);
                s.Push(t*10+(c-'0'));
                int tt;
                s.getTop(tt);
                //cout<<"tt="<<tt<<endl;

                counter=1;
            }
            else{
                s.Push(c-'0');
                int tt;
                s.getTop(tt);
               // cout<<"tt2="<<tt<<endl;
                counter=1;
            }
            c=getchar();
        }
       else
        {
           counter=0;
           char temp;
           charStack.getTop(temp);
            switch (Precede(temp,c)) {
                case '<':
                    charStack.Push(c);
                    c=getchar();
                    break;
                case '=':
                    charStack.Pop(temp);
                    c=getchar();
                    break;
                case '>':
                    char theta;

                    charStack.Pop(theta);
                    int a;

                    s.Pop(a);
                   // cout<<"a="<<a<<endl;
                    int b;
                    s.Pop(b);
                    //cout<<"b="<<b<<endl;
                    s.Push(Calculate(b,a,theta));
                default:
                    break;


            }
        }
    }
int result;
    s.getTop(result);
   cout<<"result = "<<result;
    return result;

}
