#include<iostream>     //输入的表达式要以'#'结尾，如‘5+6*3/(3-1)#’
#include<cstring>
#include<cstdio>
#include<cctype>
#include "Calculator.h"
using namespace std;

int main()
{
    //freopen("test.txt", "r", stdin);
    int n;
    cout<<"请输入算式个数"<<endl;
    cin>>n;
    while(n-->0){
        Calculator c(50,50);
        c.DoCal();
    }


    return 0;
}