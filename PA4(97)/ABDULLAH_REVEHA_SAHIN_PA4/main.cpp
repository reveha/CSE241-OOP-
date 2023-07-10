#include <iostream>

#include "SchoolManagerSystem.h"

using namespace std;
using namespace PA4;

int main(){   
    SchoolManagerSystem system;
    int choice; // for user inputs
    int choice2;
    int choice3;
    int choice4;
    string name,ID,code;

    do{ // main menu
        cout<<"0 exit"<<endl;
        cout<<"1 student"<<endl;
        cout<<"2 course"<<endl;
        cout<<"3 list_all_students"<<endl;
        cout<<"4 list_all_courses"<<endl;
        cout<<">> ";
        cin>>choice;
        if(choice==0){
            //exit(0);
        }
        else if(choice==1){
            do{
                cout<<"0 up"<<endl;
                cout<<"1 add_student"<<endl;
                cout<<"2 select_student"<<endl;
                cout<<">> ";
                cin>>choice2;
                if(choice2==1){
                    cin>>ID;
                    getline(cin,name);
                    Student *s1=new Student(ID,name);
                    system.addStudent(s1);
                    //system.print_student();
                }
                else if(choice2==2){
                    cin>>ID;
                    getline(cin,name);
                    if(system.isValidStudent(ID,name)){
                        do{
                            cout<<"0 up"<<endl;
                            cout<<"1 delete_student"<<endl;
                            cout<<"3 add_selected_student_to_a_course"<<endl;
                            cout<<"4 drop_selected_student_from_a_course"<<endl;
                            cout<<">> ";
                            cin>>choice3;
                            if(choice3==1){
                                system.deleteStudent(ID,name);
                                break;
                            }
                            else if(choice3==3){
                                do{
                                    cout<<"0 up"<<endl;
                                    system.printCoursesExceptTaken(ID,name);
                                    cout<<">> ";
                                    cin>>choice4;
                                    system.add_selected_student_to_a_course(ID,name,choice4);
                                }while(choice4!=0);
                            }
                            else if(choice3==4){
                                do{
                                    cout<<"0 up"<<endl;
                                    system.printCoursesJustTaken(ID,name);
                                    cout<<">> ";
                                    cin>>choice4;
                                    system.drop_selected_student_from_a_course(ID,name,choice4);
                                }while(choice4!=0);
                            }
                        }while(choice3!=0);
                    }
                }
            }while(choice2!=0);
        }
        else if(choice==2){
            do{
                cout<<"0 up"<<endl;
                cout<<"1 add_course"<<endl;
                cout<<"2 select_course"<<endl;
                cout<<">> ";
                cin>>choice2;
                if(choice2==1){
                    cin>>code;
                    getline(cin,name);
                    Course *c1=new Course(code,name);
                    system.addCourse(c1);
                }
                else if(choice2==2){
                    cin>>code;
                    getline(cin,name);
                    if(system.isValidCourse(code,name)){
                        do{
                            cout<<"0 up"<<endl;
                            cout<<"1 delete_course"<<endl;
                            cout<<"2 list_students_registered_to_the_selected_course"<<endl;
                            cout<<">> ";
                            cin>>choice3;
                            if(choice3==1){
                                system.deleteCourse(code,name);
                                break;
                            }
                            else if(choice3==2){
                                system.print_students_who_takes_a_course(code,name);
                            }
                        }while(choice3!=0);
                    }
                }
            }while(choice2!=0);
        }
        else if(choice==3){
            system.print_student();
        }
        else if(choice==4){
            system.print_courses();
        }
    }while(choice!=0);
    
    return 0;
}
