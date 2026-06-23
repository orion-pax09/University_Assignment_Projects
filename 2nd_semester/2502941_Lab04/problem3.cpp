#include <iostream>
using namespace std;
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
        return length == width;
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

class cuboid{
    private:
    int length;
    int width;
    int height;
    int area;
    public:
    //Setter
    void set_length(int l){
        if (l > 0){
            length = l;
        }
        else{
            cout << "Length must be positive." << endl;
        }
    }
    void set_width(int w){
        if (w  > 0){
            width = w;
        }
        else{
            cout << "Width must be positive." << endl;
        }
    }
    void set_height(int h){
        if (h  > 0){
            height = h;
        }
        else{

        }

    }
    void set_calculate(){
        if (length > 0 && width > 0 && height > 0){
            area = length * width * height;
            cout << area<<endl;
        }
        else{
            cout << "Length, width, and height must be positive." << endl;
        }
    }
    bool is_cube(){
        if (length == width && width == height){
            cout << "Length,width,and height are equal to each others"<<endl;
            return true;
        }
        else{
            cout << "Length,width,and height are not equal to each others"<<endl;
            return false;
        }
    }
    //Getter
    int get_length(){
        return length;
    }
    int get_width(){
        return width;
    }
    int get_Area(){
        return area;
    }
};
int main(){
    int length_1 = 3;
    int width_1=9;
    Rectangle rect;
    
    rect.set_Length(length_1);
    rect.set_Width(width_1);
    rect.set_Area();
    cout << "Area: " << rect.get_Area() << endl;
    rect.display();

    int length = 0;
    int width=-1;
    
    rect.set_Length(length);
    rect.set_Width(width);
    rect.set_Area();
    cout << "Area: " << rect.get_Area() << endl;
    rect.display();

    int length_2 = 0; 
    int width_2 = -1;
    int height_2 = 0;
    cuboid c;
    c.set_length(length_2);
    c.set_width(width_2);
    c.set_height(height_2);
    c.set_calculate();
    c.is_cube();
    c.get_Area();

    int length_3 = 10; 
    int width_3 = 10;
    int height_3 = 10;
    c.set_length(length_3);
    c.set_width(width_3);
    c.set_height(height_3);
    c.set_calculate();
    c.is_cube();
    c.get_Area();

}