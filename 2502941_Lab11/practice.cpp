#include <iostream>
using namespace std;
class Project{
    protected:
    string projectname , domain , TeamLead;
    int totalDuration , DevelopmentTime , testting_time;
    public:
    Project(const string&PN , const string & D , const string&TL , 
    int tD , int DT , int TT){
        projectname = PN;
        domain = D ;
        TeamLead = TL;
        totalDuration = tD;
        DevelopmentTime = DT;
        testting_time = TT;
    }
    virtual double calculateCost() = 0;
    virtual void  printImportant_information() = 0;
    void printproject_info(){
        cout << "Project name: "<<projectname<<endl;
        cout << "Project Domain: "<<domain<<endl;
        cout << "team lead: "<<TeamLead<<endl;
        cout<<"Total duration: "<<totalDuration<<endl;
        cout << "Development time: "<<DevelopmentTime<<endl;
        cout << "Testting time: "<<testting_time<<endl;
    } 
    virtual ~Project(){
        cout<< "Project destroyed"<<endl;
    } 
};
class Software_Project : public Project{
    public:
    Software_Project(const string&PN , const string & D , const string&TL , 
    int tD , int DT , int TT): Project(PN , D ,TL , tD , DT , TT ){}
    double calculateCost() override{
        return DevelopmentTime*600;
    }
    void  printImportant_information() override{
        cout << "Project name: "<<projectname<<endl;
        cout << "Team Lead: "<<TeamLead<<endl;
        cout << "Cost: $"<< calculateCost()<<endl;
        cout << "Total development time: "<<DevelopmentTime<<endl;

    }
    ~Software_Project(){
        cout << "Software project destroyed"<<endl;
    }
};

class Research_Project:public Project{
    public:
    Research_Project(const string&PN , const string & D , const string&TL , 
    int tD , int DT , int TT): Project(PN , D ,TL , tD , DT , TT ){}
    double calculateCost() override{
        return testting_time*400;
    }
    void  printImportant_information() override{
        cout << "Project name: "<<projectname<<endl;
        cout << "Team Lead: "<<TeamLead<<endl;
        cout << "Cost: $"<< calculateCost()<<endl;
        cout << "Total development time: "<<DevelopmentTime<<endl;
    }
    ~Research_Project(){
        cout <<"Research project destoyed"<<endl;
    }
};
class Animal{
    public:
    virtual void makesound(){
        cout << "Animal makes sound"<<endl;
    }
    virtual void eat(){
        cout << "Animal eats"<<endl;
    }
};
class dog:public Animal{
public:
    void makesound()override{
        cout << "DOg barks....."<<endl;
    }
    void eat()override{
        cout << "Dog eats bones"<<endl;
    }
};
class horse:public Animal{
    
    void makesound()override{
        cout << "Horse neighss....."<<endl;
    }
    void eat()override{
        cout << "Horse eats grass"<<endl;
    }
};
class Lion:public Animal{
    void makesound()override{
        cout << "DOg roarsss....."<<endl;
    }
    void eat()override{
        cout << "Lion eats meat"<<endl;
    }

};
class shape{
public:
virtual void draw();
virtual ~shape(){
    cout << "Shape destroyed"<<endl;
}
};
class circle:public shape{
    int radius;
    public:
    void draw()override{
        double area = 3.14*radius*radius;
        cout << "Draw circle area: "<<area<<endl;
    }
};
class square:public shape{
    int length;
    public:
    void draw()override{
        double area = length*length;
        cout << "Draw area square of: "<<area<<endl;
    }
};
class triangle:public shape{
int h,b;
public:
void draw()override{
    double area = 0.5*h*b;
    cout << "raw area of triangle: "<<area<<endl;
}
};
int main(){
    Project*p;
    Software_Project s("AI software system" , "AI" , "Hamza" , 500 , 12 , 44);
    s.printImportant_information();
    Animal *A;
    dog d;
    A = &d;
    A->eat();
    Animal*P1;
    horse h;
    P1=&h;
    P1->makesound();
    shape*s1 = new circle();
    shape*s2 = new square();
    shape*s3 = new triangle();
    shape*sh [3] = {s1 , s2 , s3}; 
    for (int i = 0 ; i < 3 ; i++){
        sh[i]->draw();
    } 
}