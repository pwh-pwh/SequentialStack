#include<iostream>     //����ı��ʽҪ��'#'��β���确5+6*3/(3-1)#��
#include<cstring>
#include<cstdio>
#include<cctype>
#include "Calculator.h"
using namespace std;

int main()
{
    //freopen("test.txt", "r", stdin);
    int n;
    cout<<"��������ʽ����"<<endl;
    cin>>n;
    while(n-->0){
        Calculator c(50,50);
        c.DoCal();
    }


    return 0;
}