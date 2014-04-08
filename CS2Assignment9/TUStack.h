#ifndef TUSTACK_H
#define TUSTACK_H
#include<iostream>
#include <string>
#include <sstream>
#include<stack>

using namespace std;

template <class T>
class TUStack
{
private:
    int size;
    T * arr;
    int count;

public:
    TUStack(void);
    TUStack(int nSize);

    TUStack(const TUStack &obj);

    void Push(T item);//TUStack item);
    T Pop();
    int Size();
    int GetCount() {return count;}
    int Position();
    T& operator[] (int);
    ~TUStack(void);

class Duplicates
{
public:
    public:
    int index;
    T item;
    string message;

    Duplicates (int i, T tItem, string m)
    {
        index = i;
        item = tItem;
        message = m;
    }
};
class EmptyPop
{
public:
    public:
    int index;
    int size;
    string message;

    EmptyPop (int i, int s, string m)
    {
        index = i;
        size = s;
        message = m;
    }
};
class OutOfBounds
{
public:
    public:
    int index;
    int size;
    string message;

    OutOfBounds (int i, int s, string m)
    {
        index = i;
        size = s;
        message = m;
    }
};
};
//CONSTRUCTORS
template <class T>
TUStack<T>::TUStack()
{
    size = 0;
    arr = NULL;
    count = 0;
}
template <class T>
TUStack<T>::TUStack( int nSize)
{
    size = nSize;
    arr = new T [nSize]; 
    count = 0;
}

//COPY CONSTRUCTOR
template <class T>
TUStack<T>::TUStack(const TUStack & obj)
{
    size = obj.size;
    arr = new T[size];
    for( int i=0; i<size; i++)
    {
        arr[i]= obj.arr[i];
    }
}

//PUSH AND POP
template <class T>
void TUStack <T>::Push(T item)
{
    for( int i=0; i<size; i++)
    {
        T arrItem = arr[i];
        if(arrItem == item) throw Duplicates ( i, item, "This item already exists on the stack.");
    }
    if(count == size) throw OutOfBounds (size, size-1, "Index is larger than the size of the array.");
    else
    {
        arr[count]=item;
        count++;
    }
}
template < class T >
T TUStack<T>::Pop()
{
    if(count==0) throw EmptyPop (0, size, "There are no items in this stack.");
    T value = arr[count-1];
    T empty = (T) " ";
    arr[count-1] = empty;
    count--;
    return value;
}

//SIZE AND POSITION
template <class T>
int TUStack<T>::Size()
{
    return size;
}
template< class T>
int TUStack<T>::Position()
{
    return count;
}
template <class T>

//OVERLOADED OPERATOR
T& TUStack <T> ::operator[] (int i)
{
    if( i < 0) throw OutOfBounds (i, size, "Index is negative");
    else if (i >= size) throw OutOfBounds (i, size, "Index is bigger than array's size");
    else return arr [i];
}

//DESTRUCTOR
template <class T>
TUStack<T>::~TUStack(void)
{
    delete [] arr;
}
#endif

