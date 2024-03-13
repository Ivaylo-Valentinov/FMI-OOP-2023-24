#include "event.h"
#include <cstring>

Event::Event() {
    this->copy("N/A", "N/A", Time(0, 0, 0), Time(0, 0, 0));
}

Event::Event(char const* title, char const* organizer, Time const start_time, Time const end_time) {
    this->copy(title, organizer, start_time, end_time);
}

Event::Event(Event const& other_event) {
    this->copy(other_event.title, other_event.organizer, other_event.start_time, other_event.end_time);
}

Event& Event::operator=(Event const& other_event) {
    if(this != &other_event) {
        this->copy(other_event.title, other_event.organizer, other_event.start_time, other_event.end_time);
    }

    return *this;
}

Event::~Event() {
    delete[] this->title;
    delete[] this->organizer;
}

void Event::copy(char const* title, char const* organizer, Time const start_time, Time const end_time) {
    int title_len = strlen(title);
    int organizer_len = strlen(organizer);

    if (this->title != nullptr) {
        delete[] this->title;
    }
    this->title = new char[title_len + 1];
    strcpy(this->title, title);


    if (this->organizer != nullptr) {
        delete[] this->organizer;
    }
    this->organizer = new char[organizer_len + 1];
    strcpy(this->organizer, organizer);
    
    this->start_time = start_time;
    this->end_time = end_time;
}
