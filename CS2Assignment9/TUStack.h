#ifndef TUSTACK_H
#define TUSTACK_H
#include<iostream>
#include <string>
#include<stack>

using namespace std;

template <class T>
class TUStack
{
private:
    int size;
    T * arr;

public:
    TUStack(void);
    TUStack(int nSize);

    TUStack(const TUStack &obj);

    void Push(T item);//TUStack item);
    T Pop();
    int Size();
    int Position();
    T& operator[] (int);
    ~TUStack(void);

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
}
template <class T>
TUStack<T>::TUStack( int nSize)
{
    size = nSize;
    arr = new T [nSize];    
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
void TUStack <T>::Push(T i)
{
    int arrSize = sizeof(arr);
    arr[arrSize+1] = i;
}
template < class T >
T TUStack<T>::Pop()
{
    int arrSize = sizeof(arr);
    int value = arr[arrSize-1];
    arr[arrSize-1]=NULL;
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
    return arr;
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

//ERROR CHECKING
void OutOfBounds ( int i, int size, string m)
{
    cout<< "Index: "<<i<<endl;
    cout<< "Size: "<<size<<endl;
    cout<< "Error message: "<<m<<endl;
}
#endif

