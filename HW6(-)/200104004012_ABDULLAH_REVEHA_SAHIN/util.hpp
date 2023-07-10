#include <memory>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace PFArraySavitch{

    class temp{// just using -> operator overloading;
    public:
        int value=5;
    };

    template<class T>
    class PFArray{
    public:
        PFArray(); // Initilazes with a capacity of 50.

        PFArray(int capacityValue);

        PFArray(const PFArray<T> &oth); // Copy constructor

        class iterator: public std::iterator<std::random_access_iterator_tag, T>{ // My derivered iterator class rom random_access_iterator_tag
        public:
            iterator(T* it): it(it) {}

            ~iterator(){}

            T& operator*(){return *it;}

            T* operator->(){return it;}
            
            iterator& operator++(){ // Pre increment overloading
                it++;
                return *this;
            }

            iterator operator++(int){ // Post increment overloading
                iterator temp=it;
                it++;
                return temp;
            }

            iterator operator--(){ // Pre decrement overloading
                it--;
                return *this;
            }

            iterator operator--(int){ // Post decrement overloading
                iterator temp=it;
                it--;
                return temp;
            }

            iterator& operator+=(int x){ // Overload +=
                it+=x;
                return *this;
            }

            iterator& operator-=(int x){ // Overload -=
                it-=x;
                return *this;
            }
            
            iterator& operator=(const iterator& oth){
                it=oth.it;
                return *this;
            }

            bool operator==(const iterator& oth){
                return it==oth.it;
            }

            bool operator==(const std::shared_ptr<T>& oth){ // Overload for an iterator and shared_ptr
                return *it==*oth;
            }

            bool operator!=(const iterator& oth){
                return it!=oth.it;
            }

            bool operator!=(const std::shared_ptr<T>& oth){ // Overload for an iterator and shared_ptr
                return *it!=*oth;
            }

            bool operator<(const iterator& oth){
                return it<oth.it;
            }

            bool operator<(const std::shared_ptr<T>& oth){ // Overload for an iterator and shared_ptr
                return *it<*oth;
            }
            
            bool operator<=(const iterator& oth){
                return it<=oth.it;
            }

            bool operator<=(const std::shared_ptr<T>& oth){ // Overload for an iterator and shared_ptr
                return *it<=*oth;
            }

            bool operator>(const iterator& oth){
                return it>oth.it;
            }

            bool operator>(const std::shared_ptr<T>& oth){ // Overload for an iterator and shared_ptr
                return *it>*oth;
            }

            bool operator>=(const iterator& oth){
                return it>=oth.it;
            }

            bool operator>=(const std::shared_ptr<T>& oth){ // Overload for an iterator and shared_ptr
                return *it>=*oth;
            }

            int operator<<(int shift){
                return it<<shift;
            }
            
            int operator>>(int shift){
                return it>>shift;
            }

            iterator& operator+(int x){
                for(int i=0;i<x;i++)
                    ++it;
                return *this;
            }

            iterator& operator-(int x){
                for(int i=0;i<x;i++)
                    --it;
                return *this;   
            }

            int operator-(const iterator& oth){
                return it-oth.it;
            }

            int operator-(const std::shared_ptr<T>& oth){ // Overload for an iterator and shared_ptr
                return it-oth;
            }

            int operator+(const iterator& oth){
                return it+oth.it;
            }

            int operator+(const std::shared_ptr<T>& oth){ // Overload for an iterator and shared_ptr
                return it+oth;
            }
        private:
            T* it;
        };

        // Operator overloading for shared_ptr and int
        friend std::shared_ptr<T> operator+(std::shared_ptr<T>& obj, int x){
            return std::make_shared<T>(*obj + x);
        }

        iterator begin(){return a.get();} // My iterator begin function

        iterator end(){return a.get()+used;} // My iterator end function

        
        class const_iterator{
        public:
            const_iterator(T* it): it(it){}

            ~const_iterator(){}

            const T& operator*() const{return *it;}

            const T* operator->() const{return it;}

            const_iterator& operator++(){ // Pre increment overloading
                it++;
                return *this;
            }

            const_iterator operator++(int){ // Post increment overloading
                const_iterator temp=it;
                it++;
                return temp;
            }

            const_iterator operator--(){ // Pre decrement overloading
                it--;
                return *this;
            }

            const_iterator operator--(int){ // Post decrement overloading
                const_iterator temp=it;
                it--;
                return temp;
            }
            
            const_iterator& operator=(const const_iterator& oth){
                it=oth.it;
                return *this;
            }

            bool operator==(const const_iterator& oth) const{
                return it==oth.it;
            }

            bool operator!=(const const_iterator& oth) const{
                return it!=oth.it;
            }

            bool operator<(const const_iterator& oth) const{
                return it<oth.it;
            }
            
            bool operator<=(const const_iterator& oth) const{
                return it<=oth.it;
            }

            bool operator>(const const_iterator& oth) const{
                return it>oth.it;
            }

            bool operator>=(const const_iterator& oth) const{
                return it>=oth.it;
            }

            const_iterator& operator+(int x){
                for(int i=0;i<x;i++)
                    ++it;
                return *this;
            }

            const_iterator& operator-(int x){
                for(int i=0;i<x;i++)
                    --it;
                return *this;   
            }

            int operator<<(int shift) const{
                return it<<shift;
            }
            
            int operator>>(int shift) const{
                return it>>shift;
            }

            int operator-(const iterator& oth) const{
                  return it-oth.it;
            }

            int operator+(const iterator& oth) const{
                  return it+oth.it;
            }
        private:
            const T* it;
        };
        

        const_iterator cbegin() const{return a.get();} // My const_iterator cbegin function
        const_iterator cend() const{return a.get()+used;} // My const_iterator cend function

        void addElement(const T& oth);
        // Precondition: The array is not full
        // Postcondition: The element has been added

        bool empty() const;

        int size() const;

        void erase(iterator pos);

        void clear();

        int getCapacity() const;

        int getNumberUsed() const;

        void emptyArray();
        // Resets the number used to zero, effectively emptying array
        
        T& operator[](int index);

        PFArray<T>& operator=(const PFArray<T>& oth);

        virtual ~PFArray();// Destructor

    private:
        std::shared_ptr<T> a;
        int capacity;
        int used;
    };

     template<class T>
    PFArray<T>:: PFArray(): capacity(1),used(0){
        std::shared_ptr<T> temp(new T[capacity], std::default_delete<T[]>());
        a=temp;
    }

    template<class T>
    PFArray<T>:: PFArray(int size): capacity(size),used(0){
        std::shared_ptr<T> temp(new T[capacity], std::default_delete<T[]>());
        a=temp;
    }

    template<class T>
    PFArray<T>:: PFArray(const PFArray<T>& oth){
        std::shared_ptr<T> temp(new T[oth.capacity], std::default_delete<T[]>());

        for(int i=0;i<oth.used;i++)
            temp.get()[i] = oth.a.get()[i]; // Assigning the values into new array

        used=oth.used;
        capacity=oth.capacity;
        a=temp;
    }

    template<class T>
    void PFArray<T>:: addElement(const T& oth){
        if(used>=capacity){
            capacity+=50;

            std::shared_ptr<T> temp(new T[used+1], std::default_delete<T[]>()); // Creating new memory

            for(int i=0;i<used;i++){
                temp.get()[i]=a.get()[i]; // Assigning the shared_ptr
            }

            temp.get()[used] = oth; // Adding new element
            
            a=temp;
        }
        else{
            a.get()[used]=oth;
        }
        used++;

    }

    template<class T>
    int PFArray<T>:: size() const{
        return capacity;
    }
    
    template<class T>
    bool PFArray<T>:: empty()const{
        try{
            if(used==0){ // checking used zero or not 
                throw -1;
            }
        }
        catch(int i){
            return false;
        }
        return true;
    }

    template<class T>
    int PFArray<T>:: getCapacity()const{
        return capacity;
    }

    template<class T>
    int PFArray<T>:: getNumberUsed()const{
        return used;
    }

    template<class T>
    void PFArray<T>:: emptyArray(){
        a.reset(); // Clearing shared_ptr
        used=0;
    }

    template<class T>
    T& PFArray<T>:: operator[](int index){
        try{
            if(index>=used){ // That means index didn't used yet
                throw -1;
            }
        }
        catch(int i){
            cerr<<"Illegal index in PFArray."<<endl;
            exit(0);
        }
        return a.get()[index];
    }

    template<class T>
    PFArray<T>& PFArray<T>::operator=(const PFArray<T>& oth){ // Operator overloading for =
        used=oth.used;
        capacity=oth.capacity;
        a=oth.a;
        return *this;
    }

    template<class T>
    void PFArray<T>:: erase(iterator pos){
        try{
            // Checking the index statement
            if(pos<a || pos>=a.get()+used){
                throw -1;// Throwing -1 to understand error
            }
        }
        catch(int x){
            // Catching the int value to write error message and exit;
            cerr<<"Invalid iterator position in PFArray<T>"<<endl;
            exit(0);
        }
        for(auto it=pos;it<a.get()+used;it++){
            // Shifting elements from iterator pos to end(a+used);
            (*it)=*(it+1);
        }
        used--;
    }

    template<class T>
    void PFArray<T>:: clear(){
        used=0;
    }

    template<class T>
    PFArray<T>::~PFArray(){
        used=0; // Making zero used;
    }
    
}