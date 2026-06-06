#include <iostream>
#include <cstring>
using namespace std;
class Teacher {
private:
    int EmployeeId;
    char* name;
public:
Teacher():EmployeeId(0),name(nullptr){};
Teacher(const char*n,int id):EmployeeId(0),name(nullptr){
    EmployeeId=id;
    if (n!=nullptr){
        name = new char [strlen(n)+1];
        strcpy(name , n);
    }
}
Teacher(const Teacher& other):EmployeeId(other.EmployeeId),name(nullptr){
    if (other.name!=nullptr){
        name = new char[strlen(other.name)+1];
        strcpy(name, other.name);
    }
}
void display()const{
    cout << "Employee id: "<<EmployeeId<<endl;
    cout << "Teacher name: "<<name<<endl;
}
~Teacher(){
    if (name!=nullptr){
        delete[]name;
        name = nullptr;
    }
}
};
class Student {
private:
    char* roll_number;
    char* name;
    Teacher* TeacherList;
public:
Student():roll_number(nullptr) , name(nullptr) , TeacherList(nullptr){};
Student(const char* rollid , const char*n ,  Teacher* list):roll_number(nullptr) , name (nullptr) , TeacherList(nullptr){
    if (rollid != nullptr){
        roll_number = new char [strlen(rollid)+1];
        strcpy(roll_number , rollid);
    }
    if (n!=nullptr){
        name = new char[strlen(n)+1];
        strcpy(name,n);
    }
    TeacherList = list; //association
}
Student(const Student&others):roll_number(nullptr),name(nullptr),TeacherList(nullptr){
    if (others.roll_number!=nullptr){
        roll_number=new char [strlen(others.roll_number)+1];
        strcpy(roll_number , others.roll_number);
    }
    if (others.name!=nullptr){
        name = new char [strlen(others.name)+1];
        strcpy(name , others.name);
    }
    TeacherList=others.TeacherList;
}
void display()const{
    cout << "Student's roll no: "<<roll_number<<endl;
    cout << "Student's name: "<<name<<endl;
    if (TeacherList!=nullptr){
        TeacherList->display();
    }
}
~Student(){
    if (roll_number!=nullptr){
        delete[]roll_number;
        roll_number=nullptr;
    }
    if (name!=nullptr){
        delete[]name;
        name=nullptr;
    }       
}
};
int main(){
    Teacher obj1("Imran Ali" , 45);
    obj1.display();
    Student obj2("2502941" ,"Muhammad Hamza Khan" , &obj1);
    obj2.display();
}