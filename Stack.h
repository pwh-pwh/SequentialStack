//
// Created by CH on 2020/11/2.
//

#ifndef SEQUENTIALSTACK_STACK_H
#define SEQUENTIALSTACK_STACK_H

const int maxSize = 50;
template<class T>
class Stack {
public:
Stack(){

}
virtual bool Push(const T &x) = 0;
virtual bool Pop(T& x) = 0;
virtual bool getTop(T& x) const =0;
virtual bool IsEmpty() const = 0;
virtual  bool IsFull() const = 0;
virtual int getSize() const =0;

};


#endif //SEQUENTIALSTACK_STACK_H
