#ifndef _MY_VECTOR_H_
#define _MY_VECTOR_H_

const size_t INITIAL_CAPACITY = 10;
const size_t VECTOR_VALUE_NOT_FOUND = (size_t)-1;

class MyVector
{
private:
	size_t count;
	size_t capacity;
	int* array;

	void allocate(const size_t capacity);
	void cleanup();
	void copy(const int* arr, const size_t n);
	void checkAndIncreaseCapacity();

public:
	MyVector();
	MyVector(const MyVector& that);
	MyVector(MyVector&& that);
	MyVector& operator=(const MyVector& that);
	MyVector& operator=(MyVector&& that);
	~MyVector();

	size_t size() const;
	bool isEmpty() const;
	void append(const int value);
	void insert(const size_t pos, const int value);
	void pop();
	void remove(const size_t pos);
	void clear();
	int get(const size_t pos) const;
	void set(const size_t pos, const int value);
	size_t find(const int value) const;
};
#endif // ! _MY_VECTOR_H_
