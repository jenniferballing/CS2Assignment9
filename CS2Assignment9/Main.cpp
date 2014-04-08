#include <iostream>
#include <stack>
#include "TUStack.h"

using namespace std;
//int counter;
char *arr [10];
//string sArr[10];
int main ()
{
    //int counter = 0;
       
    //Initialize
    cout<<"Initialize the stack with ints: ";
    cout<<"Initialize the stack with strings: ";
    stack<int> intStack;
    stack<string> stringStack;

    TUStack<int> TStackInt (10);
    TUStack<string> TStackString(10);
   
    //push
    cout<<"Push ints: 123, 560, 400, 890"<<endl;
    cout<<"Push strings: Hello World, Hi Mom!"<<endl;
    intStack.push(123);
    TStackInt.Push(123);
    intStack.push(560);
    TStackInt.Push(560);
    intStack.push(400);
    TStackInt.Push(400);
    intStack.push(890);
    TStackInt.Push(890);


    stringStack.push("HelloWorld");
    TStackString.Push("HelloWorld");
    stringStack.push("HiMom!");
    TStackString.Push("HiMom!");

    //Pop
    cout<<"Pop the last number (890): "<<TStackInt.Pop()<<endl;
    cout<<"Pop the last number (890): "<<intStack.top()<<endl;
     intStack.pop();

    //copy constructor
    cout<<"Copy Constructor: "<<endl;

    cout<<"Original int stack: "<<endl;
    for(int j=0; j<sizeof(TStackInt)-1; j++)
    {
        cout<<TStackInt[j]<<endl;
    }
    cout<<"Original string stack: "<<endl;
    for( int j=0; j<sizeof(TStackString)-1; j++)
    {
        cout<<TStackString[j]<<endl;
    }
    
    TUStack <int> newTu(TStackInt);
    TUStack<string> newTuString(TStackString);
    cout<<"Copied int stack: "<<endl;
    for(int i=0; i<sizeof(newTu)-1; i++)
    {
        cout<< newTu[i]<<endl;
    }
    cout<<"Copied string stack: "<<endl;
    for(int i=0; i<sizeof(newTuString)-1; i++)
    {
        cout<< newTuString[i]<<endl;
    }
    /*stack<int> newStack;
    newStack=intStack;
    cout<<"Test case: "<<endl;
    for(int k=0; k<sizeof(newStack); k++)
    {
        cout<<newStack[k]<<endl;
    }*/
    
     
    return 0;
}

