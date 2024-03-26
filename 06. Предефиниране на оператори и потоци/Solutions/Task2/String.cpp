#include "String.h"
#include <cstring>
#include <cassert>
#define _CRT_NO_WARNINGS

String::String(const char* string)
{
	
	if (string)
	{
		unsigned int str_length = strlen(string);
		this->str = new char[str_length + 1];
		for (unsigned int i = 0; i < str_length + 1; i++)
		{
			this->str[i] = string[i];
		}
	}
	else
	{
		this->str = new char[1];
		this->str[0] = '\0';
	}
}

unsigned int String::length() const
{
	return strlen(this->str);
}

char String::operator[](unsigned int index) const
{
	assert(index < this->length());
	return this->str[index];
}


String::String(const String& string)
{
	unsigned int str_length = string.length();
	this->str = new char[str_length + 1];
	for (unsigned int i = 0; i < str_length + 1; i++)
	{
		this->str[i] = string.str[i];
	}
}

String::String(String&& string)
{
	this->str = string.str;
	string.str = nullptr;
}

String& String::operator=(const char* string)
{
	if (string && string != this->str)
	{
		delete[] this->str;
		unsigned int str_length = strlen(string);
		str = new char[str_length + 1];
		for (unsigned int i = 0; i < str_length + 1; i++)
		{
			str[i] = string[i];
		}
	}
	return *this;
}

String& String::operator=(const String& string)
{
	if (this != &string) {
		delete[] this->str;
		unsigned int str_length = string.length();
		this->str = new char[str_length + 1];
		for (unsigned int i = 0; i < str_length + 1; i++)
		{
			this->str[i] = string.str[i];
		}
	}

	return *this;
}

String& String::operator=(String&& string)
{
	if (this != &string) {
		this->str = string.str;
		string.str = nullptr;
	}

	return *this;
}

String& String::operator+=(const String& string)
{
	*this = *this + string;

	return *this;
}

String String::operator+(const String& string) const
{
	unsigned int first_length = this->length();
	unsigned int second_length = string.length();
	char* result = new char[first_length + second_length + 1];
	for (unsigned int i = 0; i < first_length; i++)
	{
		result[i] = this->str[i];
	}
	for (unsigned int i = 0; i <= second_length; i++)
	{
		result[i + first_length] = string.str[i];
	}
	return String(result);
}

bool String::empty() const
{
	return this->length() == 0;
}

const char* String::c_str() const
{
	return this->str;
}

String::~String()
{
	delete[] str;
}

String operator+(const char* first, const String& second)
{
	return second + first;
}

std::ostream& operator<<(std::ostream& os, const String& string)
{
	os << string.c_str();
	return os;
}

std::istream& operator>>(std::istream& is, String& string)
{
	const int BUFFER_SIZE = 256;
	char buff[BUFFER_SIZE];
	is >> buff;
	string = buff;
	return is;
}
