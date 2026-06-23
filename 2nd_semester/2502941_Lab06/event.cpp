#include <iostream>
using namespace std;
class Event{
  private:
  char*event_name;
  char*event_venue;
  char event_time[20];
  char event_date[20];
  public:
  Event(){
    cout << "Default constructor called"<<endl;
    event_name = nullptr;
    event_venue=nullptr;
    event_time[0] = '\0';
    event_date[0] = '\0';
  }
  Event(char event_name[20], char event_venue[50],char event_date[11],char event_time[9]){
    cout << "Overloaded constructor called"<<endl;
    this -> event_name = new char [20];
    this-> event_venue = new char [50];
    for (int i = 0 ; i < 20 ; i++){
      if (event_name[i] != '\0'){
      this ->event_name[i] = event_name[i];
      }
      else{
      this ->event_name[i] = '\0';
        break;
      }
    }
    for (int i = 0 ; i < 50 ; i++){
      if (event_venue[i]!='\0'){
        this ->event_venue[i] = event_venue[i];
      }
      else{
        this ->event_venue[i] = '\0';
        break;
      }
    }
    for (int i = 0 ; i < 20 ; i++){
      if (event_date[i]!='\0'){
        this ->event_date[i] = event_date[i];
      }
      else{
        this ->event_date[i] = '\0';
        break;
      } 
    }
    for (int i = 0 ; i < 20 ; i++){
      if (event_time[i]!='\0'){
        this ->event_time[i] = event_time[i];
      }
      else{
        this ->event_time[i] = '\0';
        break;
      } 
    }
  }
    void display(){
    cout << "Event name : "<<event_name<<endl;
    cout << "Event venue: "<<event_venue<<endl;
    cout << "Event time : "<< event_time<<endl;
    cout << "Event date : "<< event_date<<endl;
  }
  void addEventOver(){
    char name [20];
    char venue[50];
    char time  [9];
    char date [11];
    cout << "Enter the new event name: "<<endl;
    cin.getline(name , 20);
    cout << "Enter the new event venue: "<<endl;
    cin.getline(venue , 50);
    cout << "Enter the new event time: "<<endl;
    cin.getline(time , 9);
    cout << "Enter the new event date: "<<endl;
    cin.getline(date , 11);
    delete [] event_name ;
    delete [] event_venue;

    this-> event_name = new char [20];
    this -> event_venue = new char [50];
    for (int i = 0 ; i < 20 ; i++){
        if (name[i]!='\0'){
            this -> event_name[i] = name[i];
        }
        else{
            this->event_name[i] = '\0';
        }
    }
    for (int i = 0 ; i < 50 ; i++){
        if (venue[i] !='\0'){
            this -> event_venue[i] = venue[i];
        }
        else{
            this->event_venue[i] = '\0';
        }
    }
    for (int i = 0 ; i < 9 ; i++){
        if (time[i] !='\0'){
            this -> event_time[i] = time[i];
        }
        else{
            this->event_time[i] = '\0';
        }
    }
    for (int i = 0 ; i < 11 ; i++){
        if (date[i]!='\0'){
            this -> event_date[i] = date[i];
        }
        else{
            this->event_date[i] = '\0';
        }
    }
  }
  ~Event(){
    delete [] this ->event_name;
    event_name = nullptr;
    delete []  this ->event_venue;
    this -> event_venue = nullptr;
  }
};
int main(){
    int button;
    do
    {
    cout << "Press 1 to call overloaded constructor"<<endl;
    cout << "press 2 to enter input calling overloaded constructors"<<endl;
    cout << "press 3 to exit"<<endl;
    cin>>button;
    cin.ignore();
    if (button==1){
        Event events[3] = {
                Event("Gym Training", "Fitness Center", "03/22/2026", "09:00AM"),
                Event("Meeting", "Conference Room", "03/23/2026", "11:00AM"),
                Event("Party", "Banquet Hall", "03/24/2026", "07:00PM")
            };

            for (int i = 0; i < 3; i++) {
                events[i].display();
                cout << "---------------------" << endl;
            }
        }
        else if (button==2){
          int count;
          cout<<"How many event do you want to enter: "<<endl;
          cin>>count;
          cin.ignore();
          Event* events = new Event [count];
          for (int i = 0 ; i < count ; i++){
            cout<<"----------Event no. "<< i+1<<"----------"<<endl;
            events[i].addEventOver();
            events[i].display();
          }
          delete [] events;            
        }
        else{
          cout << "you exit"<<endl;
          break;
        }
      }
      while (button!=3);
    }