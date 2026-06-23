#include <iostream>
using namespace std;
class Rectangle {
    private:
    int length;
    int width;
    int area;
    public:
    //Setter
    void set_Length(int l) {
        if (l>0){
            length = l;
        }
        else {
            cout << "Length must be positive." << endl;
        }
    }
    void set_Width(int w) {
        if (w>0){
            width = w;
        }
        else {
            cout << "Width must be positive." << endl;
        }
    }
    void set_Area(){
        area = width * length;
    }
    //Getter
    int get_length() {
        return length;
    }
    int get_width() {
        return width;
    }
    bool is_square() {
        if (length == width){
            cout << "Length and width are equal to each other" << endl;
            return true;
        }
        else{
            cout << "Length and width are not equal to each other" << endl;
            return false;
        }
    }
    int get_Area() {
        return area;
    }
    void display() {
        for (int i = 0 ; i < length ; i++){
            for (int j = 0 ; j < width ; j++){
                cout << "*";
            }
            cout << endl;
        }
    }
};
int main(){
    int length;
    cout << "Enter the length of rectangle: ";
    cin >> length;
    int width;
    cout << "Enter the width of rectangle: ";
    cin >> width;
    Rectangle rect;
    rect.set_Length(length);
    rect.set_Width(width);
    rect.set_Area();
    cout << "Area: " << rect.get_Area() << endl;
    rect.display();

}