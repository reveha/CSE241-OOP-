#include "driver.hpp"
#include <fstream>

using namespace DoY;

int main(){
    fstream file;
    file.open("output.txt",ios::out);

    list<DayofYearSet::DayOfYear> days;

    days.push_back(DayofYearSet::DayOfYear(29,2));
    days.push_back(DayofYearSet::DayOfYear(19,5));

    DayofYearSet set(days);

    DayofYearSet set2(days);

    // Add some days to the set
    
    set.add(DayofYearSet::DayOfYear(1, 1));
    set.add(DayofYearSet::DayOfYear(14, 2));
    set.add(DayofYearSet::DayOfYear(31, 12));

    // Add some days to the set2
    set2.add(DayofYearSet::DayOfYear(11, 4));
    set2.add(DayofYearSet::DayOfYear(25, 11));
    set2.add(DayofYearSet::DayOfYear(31, 10));

    // Print the set of days
    cout<<"set:\n"<<set<<endl;
    file<<"set:\n"<<set<<endl;
    cout<<"set2\n"<<set2<<endl;
    file<<"set2:\n"<<set2<<endl;
    
    // Checking operator == overlaoding these if statements
    if(set==set2){
        cout<<"They are equal to each other"<<endl;
        file<<"They are equal to each other"<<endl;

    }

    // Checking operator != overlaoding these if statements
    if(set!=set2){
        cout<<"They are not equal to each other"<<endl;
        file<<"They are not equal to each other"<<endl;
    }

    // Operator + overloading
    set2=set2+DayofYearSet::DayOfYear(5,9)+DayofYearSet::DayOfYear(12,7);

    cout<<"\nAfter adding new element to set2\n"<<set2<<endl;
    file<<"\nAfter adding new element to set2\n"<<set2<<endl;


    // Operator - overloading
    set2=set2-DayofYearSet::DayOfYear(31, 10);
    cout<<"\nAfter removing an element from the set2\n"<<set2<<endl;
    file<<"\nAfter removing an element from the set2\n"<<set2<<endl;


    // Operator ^ overloading
    cout<<"Intersection of the sets: \n"<<(set^set2)<<endl;
    file<<"Intersection of the sets: \n"<<(set^set2)<<endl;


    // Operator [] overloading
    cout<<"index of 0 for set2:\n"<<set2[0]<<endl;
    file<<"index of 0 for set2:\n"<<set2[0]<<endl;
    cout<<"index of 2 for set2:\n"<<set2[2]<<endl<<endl;
    file<<"index of 2 for set2:\n"<<set2[2]<<endl<<endl;
    
    //Operator ! overloading
    cout<<"\n\nComploment of the set2\n\n"<<!set2<<endl;
    file<<"\n\nComploment of the set2\n\n"<<!set2<<endl;


    // Call by reference
    cout<<"set(before):\n"<<set<<endl;
    file<<"set(before):\n"<<set<<endl;
    change(set);    // adding (12-12) day of year with call by value
    cout<<"set(after added day of year (12-12) with call by reference):\n"<<set<<endl;
    file<<"set(after added day of year (12-12) with call by reference):\n"<<set<<endl;
    
    // Call by value
    cout<<"set2(before):\n"<<set2<<endl;
    file<<"set2(before):\n"<<set2<<endl;
    change2(set2); // adding (12-12) day of year with call by value
    cout<<"set2(after added day of year (12-12) with call by value):\n"<<set2<<endl; 
    file<<"set2(after added day of year (12-12) with call by value):\n"<<set2<<endl;


    // This object to see what happens if the user enter invalid day or month
    DayofYearSet set3;
    cout<<"Trying to add (-16,11), (16,11) and (6,13) into set3:\n"<<endl;
    file<<"Trying to add (-16,11), (16,11) and (6,13) into set3:\n"<<endl;
    set3=set3+DayofYearSet::DayOfYear(-16,11);
    set3=set3+DayofYearSet::DayOfYear(16,11);
    set3=set3+DayofYearSet::DayOfYear(6,13);

    cout<<"\nset3:\n"<<set3<<endl;
    file<<"\nset3:\n"<<set3<<endl;

    cout<<"Trying to remove an object which is not in the set3 ( Object is->(9,10) ):"<<endl;
    file<<"Trying to remove an object which is not in the set3 ( Object is->(9,10) ):"<<endl;

    set3=set3-DayofYearSet::DayOfYear(9,10);
    
    cout<<"\nset3:\n"<<set3<<endl;
    file<<"\nset3:\n"<<set3<<endl;
    file.close();
    
    return 0;
}