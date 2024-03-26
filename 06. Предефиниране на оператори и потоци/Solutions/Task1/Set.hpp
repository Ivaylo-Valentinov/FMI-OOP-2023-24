#ifndef  SET_H
#define  SET_H

class Set {
	int* elements;

	int numElements;
	int capacity;

	void resize();
	void copy(int const* elements, int numElements, int capacity);
	void move(Set&& other);
	bool contains(const int element) const;
	bool is_subset(const Set& other) const;

public:
	Set();
	Set(Set const& other);
	Set& operator= (Set const& other);
	~Set();
	Set(Set&& other);
	Set& operator= (Set&& other);

	bool addElement(int const element);
	bool deleteElement(int const element);
	void setUnion(Set const& other);
	void setIntersection(Set const& other);
	void print();

	Set operator+(const Set& other) const;
	Set& operator+=(const Set& other);

	Set operator+(const int number) const;
	Set operator*(const int number) const;

	Set operator/(const Set& other) const;
	Set& operator/=(const Set& other);

	bool operator[](const int number) const;

	bool operator<(const Set& other) const;
	bool operator>(const Set& other) const;
	bool operator==(const Set& other) const;
	bool operator<=(const Set& other) const;
	bool operator>=(const Set& other) const;
	bool operator!=(const Set& other) const;

	friend Set operator+(const int number, const Set& set);
	friend Set operator*(const int number, const Set& set);
};

#endif // ! SET_H
