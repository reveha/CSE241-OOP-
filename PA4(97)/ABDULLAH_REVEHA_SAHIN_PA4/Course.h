#ifndef _COURSE_H_
#define _COURSE_H_
#include <string>
using namespace std;

namespace PA4{
    class Student;
    class Course{
        public:
            Course();
            Course(const string eCode, const string eName);
            ~Course();
            void setName(const string eName);
            void setCode(const string eCode);
            string getName()const;
            string getCode()const;
            Student** getStudentReferences()const; 
            int getNumStudents()const;
            void list_student()const;
            void addStudent(Student* obj);
            void removeStudent(Student* obj);
            friend ostream& operator<<(ostream& out,const Course& obj);
            friend ostream& operator<<(ostream& out,const Course* obj);
            void resize();


        private:
            string name;
            string code;
            Student** student_references;
            int numStudents;
            int max;

    };
}

#endif