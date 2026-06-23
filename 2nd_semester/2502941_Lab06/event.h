#ifndef EVENT_H
#define EVENT_H

#include <iostream>
using namespace std;

class Event {
private:
    char* event_name;
    char* event_venue;
    char event_date[11];
    char event_time[9];

public:
    // Constructors
    Event();
    Event(char event_name[20], char event_venue[50],
          char event_date[11], char event_time[9]);

    // Destructor
    ~Event();

    // Setters
    void setEventName(const char name[]);
    void setEventVenue(const char venue[]);
    void setEventDate(const char date[]);
    void setEventTime(const char time[]);

    // Getters
    char* getEventName();
    char* getEventVenue();
    char* getEventDate();
    char* getEventTime();

    // Helper
    void userInput();
};

#endif