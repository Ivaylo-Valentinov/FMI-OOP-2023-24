#include <iostream>

const int MAX_LENGTH = 128;

struct Time {
	int hour;
	int minute;
	int second;

	Time normalize() const {
		Time result;
		result.hour = this->hour;
		result.minute = this->minute;
		result.second = this->second;


		while (result.second < 0) {
			result.minute--;
			result.second += 60;
		}

		while (result.minute < 0) {
			result.hour--;
			result.minute += 60;
		}

		while (result.second > 60) {
			result.minute++;
			result.second -= 60;
		}

		while (result.minute > 60) {
			result.hour++;
			result.minute -= 60;
		}

		return result;
	}

	bool is_smaller_or_equal(const Time other_time) const {
		Time first = this->normalize();
		Time second = other_time.normalize();
		return first.hour < second.hour
			|| (first.hour == second.hour
				&& (first.minute < second.minute
					|| (first.minute == second.minute
						&& first.second <= second.second)
					)
				);
	}

	Time find_difference(const Time other_time) const {
		if (!this->is_smaller_or_equal(other_time)) {
			return other_time.find_difference(*this);
		}

		Time result;
		result.hour = other_time.hour - hour;
		result.minute = other_time.minute - minute;
		result.second = other_time.second - second;

		return result.normalize();
	}

	void print() const {
		std::cout << "Hours: " << hour << std::endl
			<< "Minutes: " << minute << std::endl
			<< "Seconds: " << second << std::endl;
	}
};

struct Event {
	char title[MAX_LENGTH];
	char organizer[MAX_LENGTH];
	Time start_time;
	Time end_time;

	Time get_duration() const {
		return start_time.find_difference(end_time);
	}
};

int main() {
	int n;
	std::cin >> n;

	Event* events = new Event[n];
	Time duration;
	duration.hour = 0;
	duration.minute = 0;
	duration.second = 0;

	for (size_t i = 0; i < n; i++) {
		std::cin.ignore();
		std::cin.getline(events[i].title, MAX_LENGTH);
		std::cin.getline(events[i].organizer, MAX_LENGTH);

		std::cin >> events[i].start_time.hour >> events[i].start_time.minute >> events[i].start_time.second;
		std::cin >> events[i].end_time.hour >> events[i].end_time.minute >> events[i].end_time.second;


		Time temp = events[i].get_duration();
		duration.hour += temp.hour;
		duration.minute += temp.minute;
		duration.second += temp.second;
	}

	duration.normalize().print();

	delete[] events;
	return 0;

}
