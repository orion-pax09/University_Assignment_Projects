#include <iostream>
#include <cstring>
using namespace std;
class Style{
    private:
    char color [10];
    bool isFilled;
    public:
    Style(){
        color[0]='\0';
        isFilled = false;
        cout << "Default style () called"<<endl;
    }
    Style(const char c[],bool f){
        strncpy(color,c,9);
        color[9]='\0';
        isFilled = f;
        cout << "Parameterized cosntructor style() called"<<endl;
    }
    void setColor(const char c[]){
        strncpy(color, c, 9);
        color[9]='\0';
    }
    void setFilled(bool f){
        isFilled = f;
    }
    void print(){
        cout << "Color :"<<color<<endl;
        if (isFilled){
            cout << "Yes color is filled"<<endl;
        }
        else{
            cout << "Color is not filled"<<endl;
        }
    }
    ~Style(){
        cout << "~Style() called"<<endl;
    }
};

int main(){
    Style s1("RED" , true);
    s1.print();
}