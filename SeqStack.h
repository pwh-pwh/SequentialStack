//
// Created by CH on 2020/11/2.
//

#ifndef SEQUENTIALSTACK_SEQSTACK_H
#define SEQUENTIALSTACK_SEQSTACK_H


//
// Created by CH on 2020/11/2.
//
#include <iostream>
#include "Stack.h"
#include <assert.h>
using namespace std;
const int stackIncreament = 20;
template<class T>
class SeqStack: public Stack<T>{
public:

    SeqStack(int sz = 50);
    ~SeqStack(){
        delete [] elements;
    }
    bool Push(const T& x);
    bool Pop(T& x);
    bool getTop(T & x) const;



    bool IsEmpty()const{
        return (top == -1)?true:false;
    }
    bool IsFull()const{
        return (top == maxSize-1)?true:false;

    }
    int getSize() const{
        return top+1;
    }
    void MakeEmpty(){
        top=-1;
    }
    friend ostream& operator<<(ostream&os ,SeqStack<T> &s){
        os<<"top ="<<s.top<<endl;
        for(int i=0;i<=s.top;i++){
            os<<i<<":"<<s.elements[i]<<endl;
        }
        return os;

    }


public:
    T * elements;
    int top;
    int maxSize;
    void overflowProcess();
};
template<class T>
bool SeqStack<T>::getTop(T &x) const{
    if(IsEmpty()==true){
        return false;
    }
    x=elements[top];
    return true;
}
template<class T>
SeqStack<T>::SeqStack(int sz = 50) :top(-1),maxSize(sz){
    elements=new T[maxSize];
    assert(elements!=nullptr);
}
template<class T>
void SeqStack<T>::overflowProcess() {
    T * newArray = new T[maxSize+stackIncreament];
    if(newArray == nullptr){
        cerr<<"ÄÚ´æ·ÖÅäÊ§°Ü"<<endl;
        exit(1);
    }
    for(int i=0;i<=top;i++){
        newArray[i]=elements[i];
    }
    maxSize=maxSize+stackIncreament;
    delete [] elements;
    elements=newArray;
}

template<class T>
bool SeqStack<T>::Push(const T &x) {
    if(IsFull()==true){
        overflowProcess();
    }
    elements[++top]=x;
    return true;
}

template<class T>
bool SeqStack<T>::Pop(T& x){
    if(IsEmpty()==true){
        return false;
    }
    x=elements[top--];
    return true;
}


#endif //SEQUENTIALSTACK_SEQSTACK_H
