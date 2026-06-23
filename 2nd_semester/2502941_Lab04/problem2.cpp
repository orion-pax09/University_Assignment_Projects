#include <iostream>
using namespace std;
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
    int length ; 
    cout << "Enter the length of the cuboid:";
    cin >> length ; 
    int width;
    cout << "Enter the width:";
    cin >> width;
    int height;
    cout << "Enter the height of the cuboid:";
    cin >> height;
    cuboid c;
    c.set_length(length);
    c.set_width(width);
    c.set_height(height);
    c.set_calculate();
    c.is_cube();
    c.get_Area();
}