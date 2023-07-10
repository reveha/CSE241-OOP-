#include "Student.h"
#include "Course.h"

#ifndef _SCHOOLMANAGERSYSTEM_H_
#define _SCHOOLMANAGERSYSTEM_H_
using namespace std;


namespace PA4{
    class SchoolManagerSystem{ // Implementation of SchoolManagerSystem
        
        public:
            SchoolManagerSystem();
            ~SchoolManagerSystem();
            Course** getCourse()const;
            Student** getStudent()const;
            int getNumCourses()const;
            int getNumStudents()const;
            void addCourse( Course* obj);
            void deleteCourse(const string code, const string name);
            void addStudent( Student* obj);
            void deleteStudent(const string ID, const string name);
            void printCoursesExceptTaken(const string ID, const string name);
            void printCoursesJustTaken(const string ID, const string name);
            bool isValidStudent(const string ID, const string name);
            bool isValidCourse(const string code, const string name);
            void print_students_who_takes_a_course(const string code, const string name);
            void add_selected_student_to_a_course(const string ID, const string name, const int index);
            void drop_selected_student_from_a_course(const string ID, const string name, const int index);
            void print_student()const;
            void print_courses()const;
            void resize();

        private:
            Course** course_references;
            Student** student_references;
            int numCourses;
            int numStudents;
            int max;

    };
}
#endif