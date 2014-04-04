#include <iostream>
#include <stack>
#include "TUStack.h"

using namespace std;
int counter;
int arr [1];

template <class T>
TUStack<T>::TUStack()
{
    size = 0;
    position = NULL;
}
template <class T>
TUStack<T>::TUStack( int nSize)
{
    size = nSize;
    position = new T [nSize];    
}
template <class T>
void TUStack <T>::Push(T i)
{
    arr[counter]=i;
    counter++;
}
template <class T>
TUStack<T>::TUStack(const TUStack & obj)
{
    size = obj.size;
    position = new T[size];
    for( int i=0; i<size; i++)
    {
        position[i]= obj.position[i];
    }
}
template < class T >
T TUStack<T>::Pop()
{
    int value = arr[counter-1];
    arr[counter-1]=NULL;
    return value;
}
template <class T>
int TUStack<T>::Size()
{
    return size;
}
template< class T>
int TUStack<T>::Position()
{
    return position;
}
template <class T>
T& TUStack <T> ::operator[] (int i)
{
    return position[i];
}
template <class T>
TUStack<T>::~TUStack(void)
{
    delete [] position;
}


int main ()
{
    counter =0;
    stack<int> intStack;
    TUStack<int> stacky (10);
   
    intStack.push(123);
    stacky.Push(123);

    cout<<"intStack: "<<intStack.top()<<endl;
    intStack.pop();
    cout<<"stacky: "<<stacky.Pop()<<endl;
     
    return 0;
}

