#include <iostream>
using namespace std;
class Book{
    private:
    char*title;
    int pages;
    int BookId;
    static int totalBooks;
    public:
    Book(int page = 0 , int bookid= 0): pages(page) , BookId(bookid){
        this -> pages = page;
        this -> BookId = bookid;
        title = new char [50];
    }
    Book(int page , int bookid , char title[]){
        this -> pages = page;
        this -> BookId = bookid;
        for (int i = 0 ; i < 50 ; i++){
            this -> title[i] = title[i];
            if (title[i] == '\0'){
                break;
            }
        }
        totalBooks++;
    }
    ~Book(){
        delete [] title;
    }
    void display(){
        cout << "Book's pages: "<<pages<<endl;
        cout << "Book id: "<<BookId<<endl;
        cout << "Book title: "<<title<<endl; 
    }
    static void totalshowbooks(){
        cout << "Total books: "<<totalBooks<<endl;
    }
};
int Book::totalBooks = 0;
int main(){
    Book book(990 , 1 , "Introduction to c++");
    book.display();
    book.totalshowbooks();
}