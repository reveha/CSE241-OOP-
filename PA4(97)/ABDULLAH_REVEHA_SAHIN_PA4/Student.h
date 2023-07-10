#ifndef _STUDENT_H_
#define _STUDENT_H_ 

using namespace std;

namespace PA4{
    class Course;
    class Student{
        public:
            Student();
            Student(const string eID, const string eName);
            ~Student();
            void setID(const string eID);
            void setName(const string eName);
            string getName()const;
            string getID()const;
            Course** getCourseReferences()const;
            int getNumCourses()const;
            void addStudentToCourse(Course* obj);
            void dropStudentFromCourse(Course* obj);
            friend ostream& operator<<(ostream& out,const Student& obj);
            friend ostream& operator<<(ostream& out,const Student* obj);
            void printCourses();
            void resize();
            

        private:
            string name;
            Course** course_references;
            string id;
            int numCourses;
            int max;
    };
}
#endif


