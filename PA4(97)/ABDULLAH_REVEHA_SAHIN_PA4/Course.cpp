#include <iostream>
#include "Course.h"
#include "Student.h"

using namespace std;

namespace PA4{
    
    Course:: Course(){ // Default constructor with allocating new size
        this->name="";
        this->code="";
        max=10;
        student_references=new Student*[max];
        numStudents=0;
    }

    Course:: Course(const string eCode, const string eName){ // Parameter constructor
        this->name=eName;
        this->code=eCode;
        numStudents=0;
        max=10;
        student_references=new Student*[max];;
    }

    Course:: ~Course(){
        for(int i=0;i<numStudents;i++){
            delete student_references[i];
        }
        delete[] student_references;
    }

    // Setters and getters
    void Course:: setCode(const string eCode){
        this->code=eCode;
    }

    void Course:: setName(const string eName){
        this->name=eName;
    }
    
    string Course:: getName()const{return name;}

    string Course:: getCode()const{return code;}

    Student** Course:: getStudentReferences()const{
        return student_references;
    }

    int Course:: getNumStudents()const{return numStudents;}
    

    void Course:: resize(){ // resizeing method
        max*=2; 
        Student **temp = new Student*[max];
        std::copy(student_references,student_references+max,temp); // copying old array to temp array
        delete[] student_references;
        student_references=temp;
        
    }

    void Course:: addStudent(Student* obj){

        for(int i=0;i<numStudents;i++){ // Checking there is same student or not
            if(student_references[i]==obj){
                return;
            }
        }
        if(numStudents>=max){ // Checking size of dynamic array
            resize();
        }
        //cout<<obj<<" is added"<<endl;
        student_references[numStudents++]=obj;
    }

    void Course:: removeStudent(Student* obj){
        for(int i=0;i<numStudents;i++){
            if(student_references[i]==obj){
                student_references[i]=student_references[numStudents-1]; // making index i to last index
                student_references[numStudents-1]=nullptr;
                numStudents--;
                //cout<<obj<<" is dropped"<<endl;
                return;
            }
        }
    }

    void Course:: list_student()const{ // classic print method
        for(int i=0;i<numStudents;i++){
            cout<<student_references[i]<<endl;
        }
    }

    ostream& operator<<(ostream& out, const Course& obj){ // operator overload 
        out<<obj.getName()<<" "<<obj.getCode();
        return out;
    }

    ostream& operator<<(ostream& out, const Course* obj){ // operator overload for pointer object
        out<<obj->getName()<<" "<<obj->getCode();
        return out;
    }
}