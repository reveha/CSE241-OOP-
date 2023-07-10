#include <iostream>
#include "SchoolManagerSystem.h"
#include "Course.h"
#include "Student.h"

using namespace std;


namespace PA4{
    
    SchoolManagerSystem:: SchoolManagerSystem(){ // Default constructor which allocates memory for dynamic object arrays
        max=10; // To keep size of object
        course_references=new Course*[max];
        student_references=new Student*[max];
        numCourses=0;
        numStudents=0;
    }

    SchoolManagerSystem:: ~SchoolManagerSystem(){ // Destructor which deletes dynamic objects

        for(int i=0;i<numStudents;i++){
            delete student_references[i];
        }

        for(int i=0;i<numCourses;i++){
            delete course_references[i];
        }

        delete[] course_references;
        delete[] student_references;
    }
    
    // Getters
    Course** SchoolManagerSystem:: getCourse()const{
        return course_references;
    }
    // Getters
    Student** SchoolManagerSystem:: getStudent()const{
        return student_references;
    }
    // Getters
    int SchoolManagerSystem:: getNumCourses()const{
        return numCourses;
    }
    // Getters
    int SchoolManagerSystem:: getNumStudents()const{
        return numStudents;
    }

    void SchoolManagerSystem:: addCourse(Course* obj){ // To add a course into course object 
        for(int i=0;i<numCourses;i++){ // Checking if there is another same course or not
            if(course_references[i]==obj){
                return;
            }
        }

        course_references[numCourses++]=obj; // Adding course to array
    }

    void SchoolManagerSystem:: addStudent(Student* obj){ // To add a student into student object
        for(int i=0;i<numStudents;i++){ // Checking there is another same student or not
            if(student_references[i]==obj){
                return;
            }
        }
        
        student_references[numStudents++]=obj; // Adding student to array
    }

    void SchoolManagerSystem:: resize(){ // This function to resize dynamic arrays
        max*=2; // Allocating with max * 2 
        Student **temp = new Student*[max];
        Course **temp2 = new Course*[max];
        std::copy(student_references,student_references+max,temp); // Copying values from old array to new array;
        std::copy(course_references,course_references+max,temp2);
        delete[] student_references; // Deleting older
        delete[] course_references; // Deleting older
        student_references=temp; 
        course_references=temp2;
    }

    void SchoolManagerSystem:: deleteCourse(const string code, const string name){
        if(numCourses-1==0){ // Checking if there is only 1 course, so i need to create new empty object array(if i don't do i got segfault)
            delete[] course_references;
            course_references=new Course*[max];
            cout<<"here"<<endl;
            numCourses--;
            return;
        }
        
        for(int i=0;i<numCourses;i++){
            if(course_references[i]->getCode()==code && course_references[i]->getName()==name){
                for(int j=0;j<numStudents;j++){ // Before delete a course, i need to check every student who takes this course;
                    for(int k=0;k<student_references[j]->getNumCourses();k++){ // When a student takes this course, i need to delete course from student's Course array
                        if(student_references[j]->getCourseReferences()[k]==course_references[i]){
                            student_references[j]->dropStudentFromCourse(course_references[i]); // Dropping student from course
                            break;
                        }
                    }
                }
                course_references[i]=course_references[numCourses-1]; // Assignin last object to deleted index;
                course_references[numCourses-1]=nullptr; // Assignin last index to nullptr
                numCourses--;
                return;
            }
        }
        
    }

    void SchoolManagerSystem:: deleteStudent(const string ID, const string name){ // Same things with deleteCourse;
        if(numStudents-1==0){
            delete[] student_references;
            student_references=new Student*[max];
            numStudents--;
            return;
        }
        for(int i=0;i<numStudents;i++){
            if(student_references[i]->getName()==name && student_references[i]->getID()==ID){
                for(int j=0;j<numCourses;j++){ // Before delete a course, i need to check every course that have the student will be deleted
                    for(int k=0;k<course_references[j]->getNumStudents();k++){ // When a course has the student deleted, i need to remove the student before deleted from course's student object
                        if(course_references[j]->getStudentReferences()[k]==student_references[i]){
                            course_references[j]->removeStudent(student_references[i]); // Removing student from course
                            break;
                        }
                    }
                }
                student_references[i]=student_references[numStudents-1];
                student_references[numStudents-1]=nullptr;
                numStudents--;
                return;
            }
        }
        
    }

    void SchoolManagerSystem:: add_selected_student_to_a_course(const string ID, const string name, const int index){
        for(int i=0;i<numStudents;i++){
            if(ID==student_references[i]->getID() && name==student_references[i]->getName()){ // To find which student will be added to course
                //cout<<"merhaba"<<endl;
                if((index>0 && !(index>numCourses))){ // To check index is valid or not
                    //cout<<"merhaba2"<<endl;
                    //cout<<"added: "<<index<<endl;
                    student_references[i]->addStudentToCourse(course_references[index-1]);
                    course_references[index-1]->addStudent(student_references[i]);
                }
            }
        }
    }

    void SchoolManagerSystem:: drop_selected_student_from_a_course(const string ID, const string name, const int index){
        for(int i=0;i<numStudents;i++){
            if(ID==student_references[i]->getID() && name==student_references[i]->getName()){ //To find which student will be dropped from a course
                if((index>0 && !(index>numCourses))){ // Checking index is valid or not
                    //cout<<"dropped: "<<index<<endl;
                    student_references[i]->dropStudentFromCourse(course_references[index-1]); // Calling function to drop student from a course
                    course_references[index-1]->removeStudent(student_references[i]); // Calling function to remove student from a course
                }
                    
            }
        }
    }

    void SchoolManagerSystem:: print_courses()const{ // Just basic printing method
        for(int i=0;i<numCourses;i++){
            cout<<i+1<<course_references[i]<<endl;
        }
        cout<<endl;
    }
    
    void SchoolManagerSystem:: print_student()const{ // Just basic printing method
        for(int i=0;i<numStudents;i++){
            cout<<i+1<<student_references[i]<<endl;
        }
        cout<<endl;
    }

    


    void SchoolManagerSystem::printCoursesExceptTaken(const string ID, const string name){ // To print courses for a student which is not taken
        for(int i=0;i<numStudents;i++){
            if(ID==student_references[i]->getID() && name==student_references[i]->getName()){ // To find which student will be looked
                bool courseTaken; // To understand course taken or not
                for(int j=0;j<numCourses;j++){
                    courseTaken=false; // I need to make it false for every course
                    for(int k=0;k<student_references[i]->getNumCourses();k++){ // This loop to get courses for student who we found
                        if(course_references[j]==student_references[i]->getCourseReferences()[k]){ // If student takes that course
                            courseTaken=true; // Make it true
                            break;
                        }
                    }
                    if(!courseTaken){
                        cout<<j+1<<course_references[j]<<endl;
                    }
                }
                break;
            }
        }
    }

    void SchoolManagerSystem::printCoursesJustTaken(const string ID, const string name){
        for(int i=0;i<numStudents;i++){ // To find student will be looked
            if(ID==student_references[i]->getID() && name==student_references[i]->getName()){ // To find which student will be looked
                for(int j=0;j<student_references[i]->getNumCourses();j++){ 
                    for(int k=0;k<numCourses;k++){
                        if(student_references[i]->getCourseReferences()[j]==course_references[k]){ // If there is same course, printing them
                            cout<<k+1<<course_references[k]<<endl;
                        }
                    }
                }
                break;
            }
        }
        
    }


    

    void SchoolManagerSystem:: print_students_who_takes_a_course(const string code, const string name){ // This function to print students who takes same courses
        for(int i=0;i<numCourses;i++){ // To find course will be used
            if(course_references[i]->getCode()==code && course_references[i]->getName()==name){
                for(int j=0;j<numStudents;j++){ // To search every student courses
                    for(int k=0;k<student_references[j]->getNumCourses();k++){ // This is for every student courses
                        if(student_references[j]->getCourseReferences()[k]==course_references[i]){
                            cout<<j+1<<" "<<student_references[j]<<endl;
                        }
                    }
                }
            }
        }
    }

    bool SchoolManagerSystem:: isValidStudent(const string ID, const string name){ // To understand there is student or not for id and name
        for(int i=0;i<numStudents;i++){
            if(ID==student_references[i]->getID() && name==student_references[i]->getName()){
                return true;
            }
        }
        return false;
    }

    bool SchoolManagerSystem:: isValidCourse(const string code, const string name){ // To understand there is course or not for code and name
        for(int i=0;i<numCourses;i++){
            if(code==course_references[i]->getCode() && name==course_references[i]->getName()){
                return true;
            }
        }
        return false;
    }
}


    /*
        void SchoolManagerSystem:: printCoursesExceptTaken(const string ID, const string name){
        bool check=false;
        for(int i=0;i<numStudents;i++){
            if(ID==student_references[i]->getID() && name==student_references[i]->getName()){
                //cout<<"printCoursesExceptTaken"<<endl;
                check=true;
                for(int j=0;j<numCourses;j++){  // seg fault olabilir   
                       
                    
                        for(int k=0;k<student_references[i]->getNumCourses();k++){ // BU FOR FAZLA
                            if(course_references[j]!=student_references[i]->getCourseReferences()[k]){
                                cout<<j+1<<course_references[j]<<endl;
                            }
                        }
                    
                }
                break;
            }
        }
        if(!check){
            return;
        }
    }
    */

    /*
        void SchoolManagerSystem:: printCoursesJustTaken(const string ID, const string name){
        bool check=false;
        for(int i=0;i<numStudents;i++){
            if(ID==student_references[i]->getID() && name==student_references[i]->getName()){
                check=true;
                for(int j=0;j<numCourses;j++){ // seg fault olabilir
                    for(int k=0;k<student_references[i]->getNumCourses();k++){ // BU FOR FAZLA
                        if(course_references[j]==student_references[i]->getCourseReferences()[k]){
                            cout<<j+1<<course_references[j]<<endl;
                        }
                    }  
                }
                break;
            }
        }
        if(!check){
            return;
        }
    }
    */