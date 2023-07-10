#include <iostream>
#include "util.hpp"

using namespace std;
using namespace PFArraySavitch;

int main()
{
    // Create an array with default capacity
    PFArray<int> pfa1;

    // Insert some elements into the array
    pfa1.addElement(20);
    pfa1.addElement(10);
    pfa1.addElement(40);
    // Test the copy constructor
    PFArray<int> pfa2(pfa1);

    // Test the assignment operator
    PFArray<int> pfa3;
    pfa3 = pfa2;

    // Test the iterator operators
    PFArray<int>::iterator i1=pfa1.begin();
    PFArray<int>::iterator i2=pfa2.begin();
    PFArray<int>::iterator i3=pfa3.begin();

    // Test the const_iterator operators
    PFArray<int>::const_iterator i4=pfa1.cbegin();
    PFArray<int>::const_iterator i5=pfa2.cbegin();
    PFArray<int>::const_iterator i6=pfa3.cbegin();
    
    pfa2.addElement(30);
    pfa3.addElement(30);
    pfa3.addElement(50);


    cout<<"Elements of pfa1 with iterator: ";
    while(i1!=pfa1.end()){
        cout<<*i1<<" ";
        ++i1;
    }
    cout<<endl;

    cout<<"Elements of pfa2 with iterator: ";
    while(i2!=pfa2.end()){
        cout<<*i2<< " ";
        ++i2;
    }
    cout<<endl;

    cout<<"Elements of pfa3 with iterator: ";
    while(i3!=pfa3.end()){
        cout<<*i3<<" ";
        ++i3;
    }
    cout<<endl;
    cout<<endl;


    cout<<"Elements of pfa1 with const_iterator: ";
    while(i4!=pfa1.cend()){
        cout<<*i4<<" ";
        ++i4;
    }
    cout<<endl;

    cout<<"Elements of pfa2 with const_iterator: ";
    while(i5!=pfa2.cend()){
        cout<<*i5<<" ";
        ++i5;
    }
    cout<<endl;

    cout<<"Elements of pfa3 with const_iterator: ";
    while(i6!=pfa3.cend()){
        cout<<*i6<<" ";
        ++i6;
    }
    cout<<endl;

    

    // Test erase operator
    pfa3.erase(--i3);

    i3=pfa3.begin();

    cout<<"After erase an element from pfa3: ";
    while(i3!=pfa3.end()){
        cout<<*i3<< " ";
        ++i3;
    }
    cout<<endl;

    // Test the subscript operator []
    for(int i=0;i<pfa1.size();i++){
        cout<<"pfa1[" << i << "] = "<<pfa1[i]<<endl;
        if(i+1==pfa1.getNumberUsed())
            break;
    }
    

    // Test the dereference operator *
    cout<<"*pfa1.begin()= "<<*pfa1.begin()<<endl;


    // Test the operator ->
    PFArray<temp> pfa;
    temp tmp;
    pfa.addElement(tmp);
    PFArray<temp>::iterator it=pfa.begin();
    cout<<"->pfa.begin()= "<<it->value<<endl;

    // Test std::find
    PFArray<int>::iterator find_result=std::find(pfa3.begin(),pfa3.end(),30);
    
    if(find_result!=pfa3.end()){
        cout<<"30 found in pfa3!"<<endl;
    }
    else{
        cout<<"30 not found in pfa3."<<endl;
    }

    // Test std::sort
    std::sort(pfa1.begin(),pfa1.end()); // there is an error
    cout<<"Elements of sorted pfa1: ";

    for(PFArray<int>::iterator it=pfa1.begin();it!=pfa1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    
    // Test std::for_each
    cout<<"Elements of pfa2 multiplied by 2: ";
    std::for_each(pfa2.begin(),pfa2.end(),[](int& x){x*=2;}); // find another way to sovle function definition in for_each

    

    for(PFArray<int>::iterator it=pfa2.begin();it!=pfa2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    

    return 0;
}
