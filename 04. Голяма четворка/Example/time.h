#ifndef  TIME_H
#define TIME_H

class Time {
private:
	int hour;
	int minute;
	int second;

public:
	Time(int hour, int minute, int second);

    // the big 4
    Time();
    Time(Time const& other_time);
    Time& operator= (Time const& other_time);
    ~Time();
    // end of big 4

	int get_hour();

	int get_minute();

	int get_second();

	void set_hour(const int hour);

	void set_minute(const int minute);

	void set_second(const int second);

	bool is_smaller_or_equal(const Time other_time) const;

	Time find_difference(const Time other_time) const;

	void print() const;
};

#endif // ! TIME_H
