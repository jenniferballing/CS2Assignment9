#ifndef TUSTACK_H
#define TUSTACK_H
#include<iostream>
#include <string>
#include<stack>

template <class T>
class TUStack
{
private:
    int size;
    T * position;

public:
    TUStack(void);
    TUStack(int nSize);

    TUStack(const TUStack & obj);

    void Push(T item);//TUStack item);
    T Pop();
    int Size();
    int Position();
    T& operator[] (int);
    ~TUStack(void);
};
#endif

