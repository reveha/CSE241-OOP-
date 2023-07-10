#include <iostream>
#include <vector>
#include <list>

#ifndef _driver_hpp_
#define _driver_hpp_



using namespace std;

namespace DoY{
    class DayofYearSet
{
public:
    // Inner class to represent a day of the year
    class DayOfYear
    {
    public:
        DayOfYear(int day, int month);

        // To check day and month is valid or not
        bool isValid(int day, int month);
        
        int getDay() const;
        int getMonth() const;
        void setDay(int);
        void setMonth(int);

    private:
        int day_;
        decltype(day_) month_; // decltype variable
    };
    
    // No parameter constructor
    DayofYearSet(){}

    // Constructor takes a list of DayOfYear objects
    DayofYearSet(list <DayofYearSet::DayOfYear> days);

    // Destructor
    ~DayofYearSet();

    // Adding the first element of (this) object to oth object which is parameter with call by reference
    friend void change(DayofYearSet& oth);

    // Adding the first element of (this) object to oth object which is parameter with call by value
    friend void change2(DayofYearSet oth);

    // Add a DayOfYear object to the set
    void add(const DayOfYear& dayOfYear);
    
    // Removing an element from the set
    DayofYearSet& remove(const DayOfYear& dayOfYear);

    // Comparing the 2 DayofYearSet objects
    bool compare(const DayofYearSet& oth)const;

    // Returning number of elements
    int size()const;

    // Getting the vector of DayOfYearSet
    vector<DayofYearSet::DayOfYear> getDays()const;

    // Print the set of days
    friend ostream& operator<<(ostream& out, const DayofYearSet& set);

    // Print the object of set
    friend ostream& operator<<(ostream& out, const DayofYearSet::DayOfYear& obj);

    // Comparing the 2 DayofYearSet objects
    bool operator==(const DayofYearSet& oth)const;

    // Comparing the 2 DayofYearSet objects
    bool operator!=(const DayofYearSet& oth)const;

    // Adding an element to set
    DayofYearSet operator+(const DayOfYear& obj);

    // Removing an element from the set
    DayofYearSet operator-(const DayOfYear& obj);

    // Returning the intersection of the sets
    DayofYearSet operator^(const DayofYearSet& oth);

    // Returning the comploment set
    DayofYearSet operator!();

    // Returning the element at given position
    DayOfYear operator[](const int index);
    private:
    vector<DayOfYear> days_;
    };
}



#endif