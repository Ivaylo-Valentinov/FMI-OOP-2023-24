#ifndef  _STRING_H
#define  _STRING_H
#include <iostream>

class String
{
private:
	char* str;

public:
	String(const char* string = "");
	unsigned int length() const;
	String(const String& string);
	String(String&& string);
	char operator[](unsigned int index) const;
	String& operator=(const char* string);
	String& operator=(const String& string);
	String& operator=(String&& string);
	String& operator+=(const String& string);
	String operator+(const String& string) const;
	bool empty() const;
	const char* c_str() const;
	~String();
};

String operator+(const char* first, const String& second);
std::ostream& operator<<(std::ostream& os, const String& string);
std::istream& operator>>(std::istream& is, String& string);

#endif // ! STRING_H
