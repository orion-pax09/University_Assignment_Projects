#include <iostream>
using namespace std;
class BIGGERINT{
    private:
    int*big_int_;
    int int_length_;
    public:
    BIGGERINT(){
        big_int_ = nullptr;
        int_length_ = 0;
    }
    BIGGERINT(const int* obj , int size){
        this ->int_length_ = size;
        this -> big_int_ = new int [int_length_];
        for (int i = 0 ; i < int_length_ ; i++){
            this -> big_int_[i] = obj[i];
        }
    }
    BIGGERINT(const BIGGERINT & obj){
        cout << " - - - Copy constructor called - - - "<<endl;
        this ->int_length_ = obj.int_length_;
        this -> big_int_ = new int [int_length_];
        for (int i = 0 ; i < int_length_ ; i++){
            this -> big_int_[i] = obj.big_int_[i];
        }
    }
    void assign(const int * big_int, int size){
            delete [] big_int_;
        int_length_ = size;
        this -> big_int_ = new int [int_length_];
        for (int i = 0 ; i < int_length_ ; i++){
            this -> big_int_[i] = big_int[i];
        }
    }
    void assign (const BIGGERINT&obj){
        delete [] big_int_;
        int_length_ = obj.int_length_;
        this -> big_int_ = new int [int_length_];
        for (int i = 0 ; i < int_length_ ; i++){
            this -> big_int_[i] = obj.big_int_[i];
        }
    }
void append(const int* big_int, int size){
    if (big_int == nullptr || size <= 0){
        return;
    }

    int* newarray = new int[int_length_ + size];

    for (int i = 0; i < int_length_; i++){
        newarray[i] = this->big_int_[i];
    }

    for (int i = 0; i < size; i++){
        newarray[int_length_ + i] = big_int[i];
    }

    delete[] this->big_int_;
    this->big_int_ = newarray;
    this->int_length_ += size;
}
    void append(const BIGGERINT&obj){
        int new_Size = int_length_ + obj.int_length_;
        int*newarray = new int[new_Size];
        for (int i = 0 ; i < int_length_ ; i++){
            newarray[i] = big_int_[i];
        }
        for (int i = 0 ; i < obj.int_length_ ; i++){
            newarray[int_length_ + i] =  obj.big_int_[i];
        }
        delete [] big_int_;
        this -> big_int_ = newarray;
        this -> int_length_ = new_Size;
    }
    int ToCOmpare(const BIGGERINT&obj){
        if (this -> int_length_ > obj.int_length_){
            return 2;
        }
        else if (this -> int_length_ < obj.int_length_){
            return 1;
        }
        else{
            for (int i = 0 ; i < int_length_ ; i++){
                if (this -> big_int_[i] > obj.big_int_[i]){
                    return 2;
                }
                else if (this -> big_int_[i] < obj.big_int_[i]){
                    return 1;
                }
            }
            return 0;
        }
    }
    int ToCOmpare(const int* big_int, int size){
        if (this -> int_length_ > size){
            return 2;
        }
        else if  (this -> int_length_ < size){
            return 1;
        }
        else{
            for (int i = 0 ; i < int_length_ ; i++){
                if (this -> big_int_[i] > big_int[i] ){
                    return 2;

                }
                else if (this -> big_int_[i] < big_int[i]){
                    return 1;
                }
            }
            return 0;
        }
    }
    void display(){
        cout << "The address array of object: "<<big_int_<<endl;
        for (int i = 0 ; i < int_length_ ; i++){
            cout << big_int_[i]<<" ";
        }
        cout << endl;
        cout << "The length of array is : "<<int_length_<<endl;
    }
    ~BIGGERINT(){
        delete [] big_int_;
    }
};
int main(){
    int array[] ={3,4,5,6,7,8,9};
    BIGGERINT obj1(array , 6);
    BIGGERINT obj2 = obj1;
    obj1.display();
    obj2.display();
}