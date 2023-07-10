#include <iostream>
#include "Student.h"
#include "Course.h"

using namespace std;

namespace PA4{
    
    Student:: Student(){ // default constructor
        max=10;
        this->name="";
        this->id="";
        course_references=new Course*[max];
        numCourses=0;
    }

    Student:: Student(const string eID, const string eName){
        max=10;
        this->id=eID;
        this->name=eName;
        course_references=new Course*[max];
        numCourses=0;
    }
    
    Student:: ~Student(){
        for(int i=0;i<numCourses;i++){
            delete course_references[i];
        }
        delete[] course_references;
    }

    //setter and getters
    void Student:: setID(const string eID){
        this->id=eID;
    }

    void Student:: setName(const string eName){
        this->name=eName;
    }
    
    string Student:: getName()const{return name;}
    
    string Student:: getID()const{return id;}

    Course** Student:: getCourseReferences()const{
        return course_references;
    }

    int Student:: getNumCourses()const{
        return numCourses;
    }

    void Student:: resize(){ // resize method with same algorithm in Course.cpp
        max*=2;
        Course **temp = new Course*[max];
        std::copy(course_references,course_references+max,temp);
        delete[] course_references;
        course_references=temp;
        
    }
   
    void Student:: addStudentToCourse(Course* obj){

        for(int i=0;i<numCourses;i++){ // Checking student is already exist or not
            if(course_references[i]==obj){
                return;
            }
        }
        if(numCourses==max){ // Checking the size of array
            this->resize();
        }
        
        //cout<<obj<<" is added"<<endl;
        course_references[numCourses++]=obj;
    }

    void Student:: dropStudentFromCourse(Course* obj){
        for(int i=0;i<numCourses;i++){
            if(course_references[i]==obj){
                course_references[i]=course_references[numCourses-1]; // Changing index i with last index
                course_references[numCourses-1]=nullptr; // assigning last index to nullptr
                numCourses--;
                //cout<<obj<<" is dropped"<<endl;
                return;
            }
        }
    }

    ostream& operator<<(ostream& out, const Student& obj){ // operator overlaod for <<
        out<<obj.getName()<<" "<<obj.getID();
        return out;
    }

    ostream& operator<<(ostream& out,const Student* obj){ // operator overlaod for << pointer object
        out<<obj->getName()<<" "<<obj->getID();
        return out;
    }

    void Student:: printCourses(){
        for(int i=0;i<numCourses;i++){   
            cout<<course_references[i]<<endl;
        }
    }


}