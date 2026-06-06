/*#include <iostream>
using namespace std;
class Class{
    private:
    int n ;
    int m ;
    int**Arr;
    public:
    Class(int m = 0, int n = 0 ){
        this-> m = m ;
        this -> n = n;
        if (m == 0 || n == 0){
            Arr = nullptr;
        }
        Arr = new int* [n];
        for (int i = 0 ; i < n ; i++){
            Arr[i] = new int[m];
        }
    }
    Class(const Class&obj){
        this ->n = obj.n;
        this->m = obj.m;
        for (int i = 0 ; i < obj.n ; i++){
            Arr[i] = new int[m];
            for (int j = 0 ; j < obj.m ; i++){
                obj.Arr[i][j] = Arr[i][j];
            }
        }
    }
    friend class y;
    ~Class () {
        if (m !=0 || n!=0){
            for (int i = 0 ; i < n ; i ++){
                delete [] Arr[i];
            }
        }
        delete [] Arr;
        Arr = nullptr;
    }
};
class y{
    public:
    void input(Class& obj ){
        for (int i = 0 ; i < obj.n; i++){
            for (int j = 0 ; j < obj.m ; j ++){
                cin >>  obj.Arr[i][j];
            }
            cout << endl;
        }
    }
    void show(Class&obj){
        for (int i = 0 ; i < obj.n ; i++ ){
            for (int j= 0 ; j < obj.m ; j++){
                cout << obj.Arr[i][j]<<" ";
            }
            cout <<endl;
        }
    }
};
int main(){
    int o;
    cout << "Enter the rows: ";
    cin >> o;
    int r;
    cout << "Enter the cols: ";
    cin >> r;
    Class x (r , o);
    y v;
    v.input(x);
    v.show(x);
}
*/
#include <iostream>
#include <cstring>
using namespace std;

class Studenrrecord{
    private:
    char*name;
    int quiz1;
    int quiz2;
    static int count;
    public:
    Studenrrecord(){
        name = nullptr;
        quiz1 = 0;
        quiz2 = 0;
    }
    Studenrrecord(const char*n , int mark1 , int mark2){
        name = new char [strlen(n) + 1];
        strcpy(this->name , n);
        quiz1 = mark1;
        quiz2 = mark2;
        count++;
    }
    Studenrrecord(const Studenrrecord&obj){
        name = new char [strlen(obj.name)+1];
        strcpy(this->name ,obj.name);
        quiz1 = obj.quiz1;
        quiz2 = obj.quiz2;
        count++;
    }
    void setdataset(const char* , int , int);
    friend int age(Studenrrecord b);
    int average() const;
    void display() const;
    void showcount();
    ~Studenrrecord(){
        delete [] name;
    }
};
int age(Studenrrecord x){
    cout << "Age: "<<age<<endl;
}
int Studenrrecord::count=0;
void Studenrrecord::showcount(){
    cout << "Total student: "<<count<<endl;
}
void Studenrrecord::setdataset(const char*n , int mark1 , int marks2){
    delete [] name;
    name = new char [strlen(n)+1];
    strcpy(name , n);
    quiz1 = mark1;
    quiz2=marks2;
}
int Studenrrecord::average() const{
    int average = (quiz1+quiz2) / 2;
    return average;
}
void Studenrrecord::display() const{
    cout << "Name: "<<name<<endl;
    cout << "Quiz 1: "<<quiz1<<endl;
    cout << "Quiz 2: "<<quiz2<<endl;
    cout << "Average: "<< average() <<endl;
}
int main(){
    const char* name = "Muhammad hamza khan";
    Studenrrecord s1( name , 50 , 51);
    s1.display();
    age(s1);
    s1.showcount();
    Studenrrecord s2 = s1;
    s2.display();
    s2.showcount();
    s2.setdataset("Raheema mujeed" , 39 , 43);
    s2.display();
    s2.showcount();

}