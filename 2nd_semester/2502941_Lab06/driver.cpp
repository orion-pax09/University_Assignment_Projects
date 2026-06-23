#include <iostream>
#include <cstring>   // for strlen
using namespace std;

class EVENT {
private:
    char* event_name;
    char* event_venue;
    char  event_date[11];
    char  event_time[9];

public:

    EVENT() {
        cout << "Default constructor called" << endl;
        event_name  = nullptr;
        event_venue = nullptr;
        event_date[0] = '\0';
        event_time[0] = '\0';
    }

    EVENT(char* name, char* venue, char* date, char* time) {
        cout << "Overloaded constructor called" << endl;

        event_name  = new char[20];
        event_venue = new char[50];

        // Copy name
        for (int i = 0; i < 20; i++) {
            event_name[i] = name[i];
            if (name[i] == '\0') break;
        }

        // Copy venue
        for (int i = 0; i < 50; i++) {
            event_venue[i] = venue[i];
            if (venue[i] == '\0') break;
        }

        // Copy date
        for (int i = 0; i < 11; i++) {
            event_date[i] = date[i];
            if (date[i] == '\0') break;
        }

        // Copy time
        for (int i = 0; i < 9; i++) {
            event_time[i] = time[i];
            if (time[i] == '\0') break;
        }
    }

    // ✅ Copy Constructor — NEEDED because we have pointer members
    // Without this, two objects would share the same memory → CRASH on delete
    EVENT(const EVENT& other) {
        if (other.event_name != nullptr) {
            event_name = new char[20];
            for (int i = 0; i < 20; i++) {
                event_name[i] = other.event_name[i];
                if (other.event_name[i] == '\0') break;
            }
        } else {
            event_name = nullptr;
        }

        if (other.event_venue != nullptr) {
            event_venue = new char[50];
            for (int i = 0; i < 50; i++) {
                event_venue[i] = other.event_venue[i];
                if (other.event_venue[i] == '\0') break;
            }
        } else {
            event_venue = nullptr;
        }

        for (int i = 0; i < 11; i++) {
            event_date[i] = other.event_date[i];
            if (other.event_date[i] == '\0') break;
        }

        for (int i = 0; i < 9; i++) {
            event_time[i] = other.event_time[i];
            if (other.event_time[i] == '\0') break;
        }
    }

    EVENT& operator=(const EVENT& other) {
        if (this == &other) return *this; 

        delete[] event_name;
        delete[] event_venue;

        if (other.event_name != nullptr) {
            event_name = new char[20];
            for (int i = 0; i < 20; i++) {
                event_name[i] = other.event_name[i];
                if (other.event_name[i] == '\0') break;
            }
        } else {
            event_name = nullptr;
        }

        if (other.event_venue != nullptr) {
            event_venue = new char[50];
            for (int i = 0; i < 50; i++) {
                event_venue[i] = other.event_venue[i];
                if (other.event_venue[i] == '\0') break;
            }
        } else {
            event_venue = nullptr;
        }

        for (int i = 0; i < 11; i++) {
            event_date[i] = other.event_date[i];
            if (other.event_date[i] == '\0') break;
        }

        for (int i = 0; i < 9; i++) {
            event_time[i] = other.event_time[i];
            if (other.event_time[i] == '\0') break;
        }

        return *this;
    }

    // ✅ Setter
    void addEventtime(char* name, char* venue, char* date, char* time) {
        // Free old memory if already allocated
        delete[] event_name;
        delete[] event_venue;

        event_name  = new char[20];
        event_venue = new char[50];

        for (int i = 0; i < 20; i++) {
            event_name[i] = name[i];
            if (name[i] == '\0') break;
        }
        for (int i = 0; i < 50; i++) {
            event_venue[i] = venue[i];
            if (venue[i] == '\0') break;
        }
        for (int i = 0; i < 11; i++) {
            event_date[i] = date[i];
            if (date[i] == '\0') break;
        }
        for (int i = 0; i < 9; i++) {
            event_time[i] = time[i];
            if (time[i] == '\0') break;
        }
    }

    // ✅ User Input
    void USERINPUT() {
        char eventname[20];
        cout << "Enter the name of event: ";
        cin.getline(eventname, 20);

        char eventvenue[50];
        cout << "Enter the event venue: ";
        cin.getline(eventvenue, 50);

        char eventdate[11];
        cout << "Enter the date (dd/mm/yyyy): ";
        cin.getline(eventdate, 11);

        char eventtime[9];
        cout << "Enter the time (hh:mm:ss): ";
        cin.getline(eventtime, 9);

        addEventtime(eventname, eventvenue, eventdate, eventtime);
    }

    // ✅ Getters
    char* get_eventname()  { return event_name; }
    char* get_eventvenue() { return event_venue; }
    char* get_eventtime()  { return event_time; }
    char* get_eventdate()  { return event_date; }

    // ✅ Destructor
    ~EVENT() {
        delete[] event_name;
        delete[] event_venue;
    }

    void addEVENTOVER(EVENT*& event, int& size) {  
        EVENT* events = new EVENT[size + 1];

        for (int i = 0; i < size; i++) {
            events[i] = event[i];   
        }

        char eventname[20];
        cout << "Enter the event name: ";
        cin.getline(eventname, 20);

        char eventvenue[50];
        cout << "Enter the venue name: ";
        cin.getline(eventvenue, 50);

        char eventdate[11];
        cout << "Enter the event date: ";
        cin.getline(eventdate, 11);

        char eventtime[9];
        cout << "Enter the event time: ";
        cin.getline(eventtime, 9);

        events[size] = EVENT(eventname, eventvenue, eventdate, eventtime);

        delete[] event;    
        event = events;    
        size++;            
    }
};


int main() {
    int size = 3;
    EVENT* event = new EVENT[size];  

    event[0] = EVENT((char*)"Birthday",  (char*)"Hall A",      (char*)"23/03/2026", (char*)"10:00:00");
    event[1] = EVENT((char*)"Meeting",   (char*)"Room B",      (char*)"24/03/2026", (char*)"11:00:00");
    event[2] = EVENT((char*)"Seminar",   (char*)"Auditorium",  (char*)"25/03/2026", (char*)"12:00:00");

    // Display all events
    cout << "\n--- All Events ---" << endl;
    for (int i = 0; i < size; i++) {
        cout << "\nEvent " << i + 1 << ":" << endl;
        cout << "  Name  : " << event[i].get_eventname()  << endl;
        cout << "  Venue : " << event[i].get_eventvenue() << endl;
        cout << "  Date  : " << event[i].get_eventdate()  << endl;
        cout << "  Time  : " << event[i].get_eventtime()  << endl;
    }

    // Add a new event dynamically
    cout << "\n--- Adding New Event ---" << endl;
    event[0].addEVENTOVER(event, size);

    // Display updated list
    cout << "\n--- Updated Events ---" << endl;
    for (int i = 0; i < size; i++) {
        cout << "\nEvent " << i + 1 << ":" << endl;
        cout << "  Name  : " << event[i].get_eventname()  << endl;
        cout << "  Venue : " << event[i].get_eventvenue() << endl;
        cout << "  Date  : " << event[i].get_eventdate()  << endl;
        cout << "  Time  : " << event[i].get_eventtime()  << endl;
    }

    delete[] event;
    return 0;
}