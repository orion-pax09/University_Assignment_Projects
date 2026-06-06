#include <iostream>
using namespace std;
class EVENT{
    private:
    char* event_name; 
    char* event_venue;
    char event_date[11];
    char event_time[9];
    public:
    EVENT (char event_name[20], char event_venue[50],char event_date[11],char event_time[9]){
        event_name = nullptr;
        event_venue = nullptr;
        event_date = "none";
        event_time = "none";
    }
    EVENT (char*name , char*venue , char time , char date){
        this -> event_name = new char [strlen(name)+1] ;
        this -> event_venue = new char [strlen(venue)+1];
        event_time = time;
    }


};
int main(){
    char time [] = "03:55pm";
    char date [] = "03/20/2026";


}