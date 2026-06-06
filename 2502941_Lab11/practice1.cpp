#include <iostream>
using namespace std;
#include <vector>
#include <stdexcept>
class product{
    private:
    string name;
    double price;
    int stock;
    string category;
    int productID;
    public:
    product(){
        name = "";
        price = 0.0;
        stock = 10;
        category = "";
        productID = 0;
    }
    product(const string&n , double p, int s , const string&C , int PI){
        name = n;
        price = p;
        stock = s;
        category = C ;
        price = p;
        productID = PI;
    }
    int getstock()const{
        return stock;
    }
    int reducestock(int p){
        stock -=p;
        return stock;
    }
    ~product(){
        cout << "~product called"<<endl;
    }
};
class cart{
    private:
    product items;
    int itemCount;
    double totalPrice;
    string userID;
    double discount;
    public:
    void addItem(product& p1 , int qty){
            if (qty <= 0){
                throw invalid_argument("Quantity must be greater than 0");
            }
            else if (qty>p1.getstock()){
                throw runtime_error("Stock limit exceeded");
            }
            else if (p1.getstock()==0){
                throw runtime_error("Stock finished");
            }
            else{
                p1.reducestock(qty);
                cout << qty << "has been added to your cart"<<endl;
                cout << "Remaining stock: "<<p1.getstock()<<endl;
        }
    }
    ~cart(){
        cout << "~cart()"<<endl;
    }
};
int main(){
    product p1("PS5" , 50000 , 15 , "GAMING ZONE" , 25 );
    cart c;
    try
    {
        c.addItem(p1 , -2);
        c.addItem(p1 , 30);
    }
    catch(const invalid_argument& e)
    {
        cout << "Invalid: "<<e.what()<<endl;
    };
}