#include "time.h"

class Event {
private:
	char* title;
	char* organizer;
	Time start_time;
	Time end_time;

    void copy(char const* title, char const* organizer,Time const start_time, Time const end_time);

public:
    Event();
    Event(char const* title, char const* organizer, Time const start_time, Time const end_time);
    Event(Event const& other_event);
    Event& operator= (Event const& other_event);
    ~Event();

	Time get_duration() const {
		return start_time.find_difference(end_time);
	}
};