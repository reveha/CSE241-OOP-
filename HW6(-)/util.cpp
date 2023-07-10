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

        class iterator: public std::iterator<std::random_access_iterator_tag, T>{
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

            iterator& operator+=(int x){
                it+=x;
                return *this;
            }

            iterator& operator-=(int x){
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

            bool operator!=(const iterator& oth){
                return it!=oth.it;
            }

            bool operator<(const iterator& oth){
                return it<oth.it;
            }
            
            bool operator<=(const iterator& oth){
                return it<=oth.it;
            }

            bool operator>(const iterator& oth){
                return it>oth.it;
            }

            bool operator>=(const iterator& oth){
                return it>=oth.it;
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

            int operator+(const iterator& oth){
                  return it+oth.it;
            }
        private:
            T* it;
        };

        

        PFArray<T>::iterator begin(){return a;} // My iterator begin function

        PFArray<T>::iterator end(){return a+used;} // My iterator end function

        
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
        

        const_iterator cbegin() const{return a;} // My const_iterator cbegin function
        const_iterator cend() const{return a+used;} // My const_iterator cend function

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
        T *a;
        int capacity;
        int used;
    };

     template<class T>
    PFArray<T>:: PFArray(): capacity(50),used(0){
        a=new T[capacity];
    }

    template<class T>
    PFArray<T>:: PFArray(int size): capacity(size),used(0){
        a=new T[capacity];
    }

    template<class T>
    PFArray<T>:: PFArray(const PFArray<T>& oth){
        used=oth.used;
        capacity=oth.capacity;
        a=oth.a;
    }


    template<class T>
    void PFArray<T>:: addElement(const T& oth){
        std::shared_ptr<T> temp(new T[used+1], std::default_delete<T[]>()); // Creating new memory
        for(int i=0;i<used;i++)
            temp.get()[i] = a[i]; // Assigning the values into new array

        temp.get()[used] = oth;
        used++;
        for(int i=0;i<used;i++)
            a[i]=temp.get()[i];

    }

    template<class T>
    int PFArray<T>:: size() const{
        return capacity;
    }
    
    template<class T>
    bool PFArray<T>:: empty()const{
        try{
            if(used==0){
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
        used=0;
    }

    template<class T>
    T& PFArray<T>:: operator[](int index){
        try{
            if(index>=used){
                throw -1;
            }
        }
        catch(int i){
            cerr<<"Illegal index in PFArray."<<endl;
            exit(0);
        }
        return a[index];
    }

    template<class T>
    PFArray<T>& PFArray<T>::operator=(const PFArray<T>& oth){
        used=oth.used;
        capacity=oth.capacity;
        a=oth.a;
        return *this;
    }

    template<class T>
    void PFArray<T>:: erase(iterator pos){
        try{
            // Checking the index statement
            if(pos<a || pos>=a+used){
                throw -1;// Throwing -1 to understand error
            }
        }
        catch(int x){
            // Catching the int value to write error message and exit;
            cerr<<"Invalid iterator position in PFArray<T>"<<endl;
            exit(0);
        }
        for(auto it=pos;it<a+used;it++){
            // Shifting elements from iterator pos to end(a+used);
            (*it)=*(it+1);
        }
        used--;
    }

    template<class T>
    void PFArray<T>:: clear(){
        a=nullptr; // Assignin null to T* a array
        delete []a; // Deleting the array
        used=0; // Making zero used;
        
    }

    template<class T>
    PFArray<T>::~PFArray(){
        a=nullptr; // Assignin null to T* a array
        delete []a; // Deleting the array
        used=0; // Making zero used;
    }
    
}