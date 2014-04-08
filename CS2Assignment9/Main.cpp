#include <iostream>
#include <stack>
#include "TUStack.h"

using namespace std;
int i;
int main ()
{
    //Initialize
    cout<<"Initialize the stack with ints: (TStackInt (5)) "<<endl;
    cout<<"Initialize the stack with strings: (TStackString(5))"<<endl<<endl<<endl;
    TUStack<int> TStackInt (5);
    TUStack<string> TStackString(5);
   
    //push
    cout<<"Push ints: (123, 560, 400, 688, 890)"<<endl;
    cout<<"Push strings: (Hello World, DisneyLand, Wait For IIIIIIIIIt, I Love Levi, Hi Mom!)"<<endl<<endl<<endl;
    TStackInt.Push(123);
    TStackInt.Push(560);
    TStackInt.Push(400);
    TStackInt.Push(688);
    TStackInt.Push(890);
    TStackString.Push("Hello World");
    TStackString.Push("DisneyLand");
    TStackString.Push("Wait For IIIIIIIIIt");
    TStackString.Push("I love Levi!");
    TStackString.Push("Hi Mom!");

    cout<<"Print stacks with newly pushed info: "<<endl;
    cout<<"Int stack: "<<endl;
    for(int i=0; i<TStackInt.Size(); i++)
    {
        if(TStackInt[i]>0)
        {
            cout<<TStackInt[i]<<endl;
        }        
    }cout<<endl;
    cout<<"String stack: "<<endl;
    for(int i=0; i<TStackString.Size(); i++)
    {
        cout<<TStackString[i]<<endl;
    }cout<<endl;

    //Pop
    cout<<"Pop the last number (890): "<<TStackInt.Pop()<<endl;
    cout<<"Pop the last string (HiMom!): "<<TStackString.Pop()<<endl<<endl<<endl;

    //copy constructor
    cout<<"Copy Constructor: "<<endl<<endl;

    cout<<"Original int stack: "<<endl;
    for(int j=0; j<TStackInt.Size()-1; j++)
    {
        if(TStackInt[j] >0 && TStackInt[j] <111111)
        {
            cout<<TStackInt[j]<<endl;
        }
    }
    cout<<endl<<endl;
    cout<<"Original string stack: "<<endl;
    for( int j=0; j<TStackString.Size()-1; j++)
    {
        if( TStackString[j]!= " ")
        {
            cout<<TStackString[j]<<endl;
        }        
    }
    cout<<endl<<endl;
    TUStack <int> newTu(TStackInt);
    TUStack<string> newTuString(TStackString);
    cout<<"Copied int stack: "<<endl;
    for(int i=0; i<newTu.Size()-1; i++)
    {
        if(newTu[i] >0 && newTu[i] <111111)
        {
            cout<<newTu[i]<<endl;
        }
    }
    cout<<endl<<endl;
    cout<<"Copied string stack: "<<endl;
    for(int i=0; i<newTuString.Size()-1; i++)
    {
        if(newTuString [i]!= " ")
        {
             cout<< newTuString[i]<<endl;
        }
    }
    cout<<endl<<endl;
    
    //Error checking
    string input;
    cout<<"Error checking for pushing duplicate items: "<<endl;//CHECK FOR INTS
    try
    {
        while (TStackString.GetCount()+1<=TStackString.Size())
        {
            cout << "Enter an existing string to push to the stack: "; 
            getline(cin, input);

            cout<< "The string: "<<input<<" is at index: "<<TStackString.GetCount()<<"."<<endl;
            TStackString.Push(input);
        }
    }catch (TUStack<string>::Duplicates ex)
	{	
        cout<<endl;
		cout << "_______Error Report_______" << endl ;
		cout << "Input index is: " << ex.index << endl ;
        cout << "Duplicate item is: " << ex.item << endl ;
		cout << "Error Message:: " << ex.message << endl <<endl;
	}
    int userIn;
    try
    {
        while (TStackInt.GetCount()+1<=TStackInt.Size())
        {
            cout << "Enter an existing int to push to the stack: "; 
            cin>> userIn;

            cout<< "The int: "<<input<<" is at index: "<<TStackInt.GetCount()<<"."<<endl;
            TStackInt.Push(userIn);
        }
    }catch (TUStack<string>::Duplicates ex)
	{	
        cout<<endl;
		cout << "_______Error Report_______" << endl ;
		cout << "Input index is: " << ex.index << endl ;
        cout << "Duplicate item is: " << ex.item << endl ;
		cout << "Error Message:: " << ex.message << endl <<endl;
	}
    
    cout<<"Checking for out of bounds errors: "<<endl;//CHECK FOR INTS
    try
	{	while (1)
		{	
			cout << "Enter a string to push to the stack: "; 
			getline(cin, input);

            cout << "Index is: " << TStackString.GetCount() << " Its stored information is " << input <<"."<< endl << endl ;
            TStackString.Push(input);
		}
	}
	catch (TUStack<string>::OutOfBounds ex)
	{	
        cout<<endl;
		cout << "_______Error Report_______" << endl ;
		cout << "Input index is: " << ex.index << endl ;
		cout << "Stack size is: " << ex.size << endl ;
		cout << "Error Message:: " << ex.message << endl<<endl ;
	}

    cout<<"Checking for illegal index: "<<endl;//CHECK FOR STRING
    int userIndex;
     try
    {
        while (1)
        {
            cout << "Choose an illegal index to print: "; 
            cin>>userIndex;

            cout<< "The item at the index: "<<userIndex<<" is: "<<TStackInt[userIndex]<<"."<<endl;
        }
    }catch (TUStack<int>::OutOfBounds ex)
	{	
        cout<<endl;
		cout << "_______Error Report_______" << endl ;
		cout << "Input index is: " << ex.index << endl ;
		cout << "Stack size is: " << ex.size << endl ;
		cout << "Error Message:: " << ex.message << endl<<endl ;
	}

    // ILLEGAL POP CHECKING
    cout<<"Create an empty stack for illegal pop checking: (TUStack<int>intCheckStack)"<<endl;
    TUStack<int> intCheckStack(10);
    //cout<<"Create an empty stack for illegal pop checking: (TUStack<string>intCheckStack)"<<endl;
    TUStack<string> stringCheckStack(10);
     try//STRING ERRORS
    {
        while (1)
        {
            cout << "Popping the item top item off the empty int stack: "<<endl;
            intCheckStack.Pop();
        }
    }catch (TUStack<int>::EmptyPop ex)
	{	
        cout<<endl;
		cout << "_______Error Report_______" << endl ;
		cout << "Input index is: " << ex.index << endl ;
		cout << "Stack size is: " << ex.size << endl ;
		cout << "Error Message:: " << ex.message << endl <<endl;
	}

    return 0;
}

