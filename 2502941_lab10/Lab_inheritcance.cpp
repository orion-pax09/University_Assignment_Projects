#include <iostream>
#include <cstring>
using namespace std;

class person {
private:
    char* fname;
    char* lname;
protected:
    int age;
public:
    person(char* FName, char* LName, int age) {
        cout << "Person() called" << endl;
        fname = new char[strlen(FName) + 1];
        strcpy(fname, FName);
        lname = new char[strlen(LName) + 1];
        strcpy(lname, LName);
        this->age = age;
    }
    
    ~person() {
        cout << "~Person() called" << endl;
        delete[] fname;
        fname = nullptr;
        delete[] lname;
        lname = nullptr;
    }
    
    void setage(int Age) {
        if (Age < 15 || Age > 70) {
            cout << "Invalid" << endl;
        } else {
            age = Age;
        }
    }
    
    void setfirstname(char* FNAME) {
        delete[] fname;
        fname = new char[strlen(FNAME) + 1];
        strcpy(fname, FNAME);
    }
    
    void setlastname(char* LNAME) {
        delete[] lname;
        lname = new char[strlen(LNAME) + 1];
        strcpy(lname, LNAME);
    }
    
    char* getfname() {
        return fname;
    }
    
    char* getlastname() {
        return lname;
    }
    
    int getage() {
        return age;
    }
    
    void printinformation() {
        cout << getfname() << " " << getlastname() << " is a " << getage() << " years old" << endl;
    }
};

class Student : public person {
private:
    float cgpa;
public:
    Student(char* F, char* L, int A, float C) : person(F, L, A) {
        cgpa = C;
    }
    
    ~Student() {
        cout << "~Student() called" << endl;
    }
    
    void setcgpa(float C) {
        if (C < 1.00 || C > 4.00) {
            cout << "Invalid" << endl;
        } else {
            cgpa = C;
        }
    }
    
    float getcgpa() {  // Fixed typo: getcpga -> getcgpa
        return cgpa;
    }
    
    void printStudent() {
        cout << getfname() << " " << getlastname() << " is a "
             << age << " years old, his cgpa is "
             << cgpa << endl;
    }
};

class Faculty : public person {
private:
    int course_num;
    int three_digits;
public:
    Faculty(char* F, char* L, int A, int c_Count, int three_D) : person(F, L, A) {
        cout << "Faculty() called" << endl;
        course_num = c_Count;
        three_digits = three_D;
    }
    
    ~Faculty() {
        cout << "~Faculty() called" << endl;
    }
    
    
    void setcoursenum(int num) {
        if (num < 0 || num > 5) {
            cout << "Invalid course number" << endl;
        } else {
            course_num = num;
        }
    }
    
    void setthreedigits(int three_D) {
        three_digits = three_D;
    }
    
    void printFaculty() {
        cout << "Faculty member name: " << getfname()
             << " " << getlastname() << " , Age: "
             << age<< " , Number of courses: "
             << course_num << " Ext. " << three_digits << endl;
    }
};

class Undergraduate : public Student {  // Fixed: changed from 'undergraduate' to 'Undergraduate' for consistency
private:
    char* FYP_Name;  // Fixed typo: FYP_NAme -> FYP_Name
public:
    Undergraduate(char* fname, char* lname, int A, float C, char* fypname) 
        : Student(fname, lname, A, C) {
        cout << "Undergraduate() constructor called" << endl;
        FYP_Name = new char[strlen(fypname) + 1];
        strcpy(FYP_Name, fypname);
    }
    
    ~Undergraduate() {
        cout << "~Undergraduate() called" << endl;
        delete[] FYP_Name;
        FYP_Name = nullptr;
    }
    
    void setfypname(char* fypNAME) {
        delete[] FYP_Name;
        FYP_Name = new char[strlen(fypNAME) + 1];
        strcpy(FYP_Name, fypNAME);
    }
    
    char* getfyp() {
        return FYP_Name;
    }
    
    void printUndergraduate() {  // Fixed: printundergraduate -> printUndergraduate
        cout << getfname() << " " << getlastname() 
             << " is an undergraduate student, his cgpa "
             << getcgpa() << " and his final year project is "
             << getfyp() << endl;
    }
};

class Graduate : public Student {
private:
    char* Thesistopic;
public:
    Graduate(char* F, char* L, int A, char* thesistpc, float C) 
        : Student(F, L, A, C) {
        Thesistopic = new char[strlen(thesistpc) + 1];
        strcpy(Thesistopic, thesistpc);
        cout << "Graduate() constructor called" << endl;
    }
    
    ~Graduate() {
        cout << "~Graduate() called" << endl;
        delete[] Thesistopic;
        Thesistopic = nullptr;
    }
    
    void setthesistopic(char* T) {
        delete[] Thesistopic;
        Thesistopic = new char[strlen(T) + 1];
        strcpy(Thesistopic, T);
    }
    
    char* getthesisname() {
        return Thesistopic;
    }
    
    void printGraduate() {
        cout << getfname() << " " << getlastname() 
             << " is a graduate student, his cgpa "
             << getcgpa() << " and his thesis topic is "
             << getthesisname() << endl;
    }
};

int main() {
    Student s("Ted", "Thompson", 22, 3.91);
    Faculty f("Richard", "Karp", 45, 2, 420);
    s.printStudent();
    f.printFaculty();
    
    Undergraduate u("Ted", "Thompson", 22, 3.91, "The event");
    u.printUndergraduate();
    
    Graduate g("Arnold", "Gates", 25, "Distributed algorithm", 3.01);
    g.printGraduate();
    
    return 0;
}