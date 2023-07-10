#include "driver.hpp"



namespace DoY{
    // Constructor
    DayofYearSet::DayofYearSet(list<DayofYearSet::DayOfYear> arr){
        list<DayofYearSet::DayOfYear>:: iterator it = arr.begin();
        for(;it!=arr.end();it++){
            days_.push_back(*it);
        }
    }

    // Adding the first element of (this) object to oth object which is parameter with call by reference
    void change(DayofYearSet& oth){
        oth.add(DayofYearSet::DayOfYear(12,12)); 
    }

    // Adding the first element of (this) object to oth object which is parameter with call by value
    void change2(DayofYearSet oth){
        oth.add(DayofYearSet::DayOfYear(12,12));
    }

    // Add a DayOfYear object to the set
    void DayofYearSet::add(const DayOfYear& dayOfYear){
        // To solve invalid day or month entered
        if(dayOfYear.getDay()==0){
            return;
        }
        for(auto i: this->getDays()){
            if(i.getDay()==dayOfYear.getDay() && i.getMonth()==dayOfYear.getMonth()){
                cerr<<"There is already a element for that day and month: "<<i.getDay()<<"-"<<i.getMonth()<<endl;
                return;
            }
        }
        //cout<<dayOfYear.getDay()<<"-"<<dayOfYear.getMonth()<<endl;
        days_.push_back(dayOfYear);
    }

    // Removing an element from set
    DayofYearSet& DayofYearSet::remove(const DayOfYear& dayOfYear){
        int index=0;

        // Finding the index of element  that will be deleted from the set
        for(auto i:this->getDays()){
            if(i.getDay()==dayOfYear.getDay() && i.getMonth()==dayOfYear.getMonth()){
                break;
            }
            index++;
        }

        // Checking to understand there is an element or not which will be deleted
        if(index==this->size()){
            cerr<<"There is no element for "<<dayOfYear.getDay()<<"-"<<dayOfYear.getMonth()<<endl;
            return *this;   
        }

        // Erasing the index of element
        days_.erase(days_.begin()+index);

        return *this;
    }

    // Returning the number of elements in object
    int DayofYearSet:: size() const{
        return this->getDays().size();
    }

    // Comparing two objects
    bool DayofYearSet:: compare(const DayofYearSet &oth)const{
        // Checking the sizes of two objects
        if(this->size()!=oth.size())
            return false;

        // Checking the indexes of objects and comparing them for day, month and year one by one
        for(int i=0;i<this->size();i++){
            if(this->getDays()[i].getDay()!=oth.getDays()[i].getDay() || 
                this->getDays()[i].getMonth()!=oth.getDays()[i].getMonth()){
                return false;
            }
        }
        return true;
    }

    // Print the set of days with operator overloading
    ostream& operator<<(ostream& out, const DayofYearSet& set){
        for (auto day : set.getDays())
            out << day.getDay() << "-" << day.getMonth()<< endl;
        return out;
    }
    // Print the object of the set
    ostream& operator<<(ostream& out, const DayofYearSet::DayOfYear& set){
        out<<set.getDay()<<"-"<<set.getMonth()<<endl;
        return out;
    }

    // Comparing the 2 DayofYearSet objects with operator overloading
    bool DayofYearSet:: operator==(const DayofYearSet& oth)const{
        return compare(oth) ? true : false;
    }

    // Comparing the 2 DayofYearSet objects with operator overloading
    bool DayofYearSet:: operator!=(const DayofYearSet& oth)const{
        return !compare(oth) ? true : false;
    }

    // Adding an element to set with call by reference
    DayofYearSet DayofYearSet:: operator+(const DayOfYear& obj){
        this->add(obj);
        return *this;
    }

    // Removing an element from the set
    DayofYearSet DayofYearSet:: operator-(const DayOfYear& obj){
        remove(obj);
        return *this;
    }

    // Returning the intersection of the sets
    DayofYearSet DayofYearSet:: operator^(const DayofYearSet& oth){
        DayofYearSet temp;
        for(int i=0;i<this->size();i++){
            // Checking the same elements
            for(auto j=0;j<oth.size();j++){
                if(this->getDays()[i].getDay()==oth.getDays()[j].getDay() && 
                    this->getDays()[i].getMonth()==oth.getDays()[j].getMonth()){
                // Adding the new object to set
                temp=temp+DayofYearSet::DayOfYear(getDays()[i].getDay(),getDays()[i].getMonth());
            }
            }
        }
        return temp;
    }

    // Returning the comploment set
    DayofYearSet DayofYearSet:: operator!(){
        DayofYearSet temp;
        bool check=true;
        for(auto i=1,j=1;i<33,j<13;i++){
            if(j==12 && i==32){
                break;
            }
            if(j==2 && i==30){
                j++;
                i=0;
                continue;
            }

            else if((j==4 || j==6 || j==9 || j==11 ) && i==31){
                j++;
                i=0;
                continue;
            }

            else if((j==1 || j==3 || j==5 || j==7 || j==8 || j==10) && i==32){
                j++;
                i=0;
                continue;
            }

            for(auto k=0;k<this->size();k++){
                if(i==this->getDays()[k].getDay() && j==this->getDays()[k].getMonth()){
                    check=false;
                }
            }
            if(check)
                temp.days_.push_back(DayofYearSet::DayOfYear(i,j));
            check=true;
        }
        return temp;
    }

    // Returning the element at given position
    DayofYearSet::DayOfYear DayofYearSet:: operator[](const int index){
        if(index>=this->size()){
            cerr<<"Out of the range!"<<endl;
            exit(1);
        }
        return this->getDays()[index];
    }

    // Inner class to represent a day of the year
    DayofYearSet::DayOfYear::DayOfYear(int day=1, int month=1){        
        if(isValid(day,month)){
            //assigning day and month
            day_=day;
            month_=month;
        }
        else{
            day_=0;
            month_=0;
        }
    }

    // To check day and month is valid or not
    bool DayofYearSet::DayOfYear::isValid(int day, int month){
        // Check if the day and month are valid
        if (day < 1 || day > 31){
            cerr<<"Invalid day: "<<day<<endl;
            return false;
        }
        if (month < 1 || month > 12){
            cerr<<"Invalid month: "<<month<<endl;
            return false;
        }
        // Check if the day is valid for the month
        if (month == 2 && day > 29){
            cerr<<"Invalid day for February: "<<day<<endl;
            return false;
        }
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30){
            cerr<<"Invalid day for this month: "<<day<<endl;
            return false;
        }
        return true;
    }

    DayofYearSet::~DayofYearSet(){
        days_.clear();
    }

    vector<DayofYearSet::DayOfYear> DayofYearSet::getDays() const{
        return days_;
    }

    int DayofYearSet::DayOfYear::getDay() const{
        return day_;
    }

    int DayofYearSet::DayOfYear::getMonth() const{
        return month_;
    }
    
    void DayofYearSet::DayOfYear::setDay(int x){
        day_=x;
    }

    void DayofYearSet::DayOfYear::setMonth(int x){
        month_=x;
    }
}
