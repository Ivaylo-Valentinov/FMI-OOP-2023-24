#include "MyVector.h"
#include <cassert>

void MyVector::allocate(const size_t capacity)
{
	this->capacity = capacity;
	this->array = new int[capacity];
}

void MyVector::cleanup()
{
	delete[] array;
}

void MyVector::copy(const int* arr, const size_t n)
{
	assert(n <= capacity);
	for (size_t i = 0; i < n; i++) {
		array[i] = arr[i];
	}
	count = n;
}

void MyVector::checkAndIncreaseCapacity()
{
	assert(count <= capacity);
	if (count == capacity) {
		int* oldArray = array;
		allocate(2 * capacity);
		copy(oldArray, count);
		delete[] oldArray;
	}
}

MyVector::MyVector() : count{ 0 }
{
	allocate(INITIAL_CAPACITY);
}

MyVector::MyVector(const MyVector& that)
{
	allocate(that.capacity);
	copy(that.array, that.count);
}

MyVector::MyVector(MyVector&& that) :
	count{ that.count }, capacity{ that.capacity }, array{ that.array }
{
	that.array = nullptr;
}

MyVector& MyVector::operator=(const MyVector& that)
{
	if (this != &that) {
		cleanup();
		allocate(that.capacity);
		copy(that.array, that.count);
	}
	return *this;
}

MyVector& MyVector::operator=(MyVector&& that)
{
	if (this != &that) {
		count = that.count;
		capacity = that.capacity;
		array = that.array;
		that.array = nullptr;
	}
	return *this;
}

MyVector::~MyVector()
{
	cleanup();
}

size_t MyVector::size() const
{
	return count;
}

bool MyVector::isEmpty() const
{
	return size() == 0;
}

void MyVector::append(const int value)
{
	checkAndIncreaseCapacity();
	array[count] = value;
	count++;
}

void MyVector::insert(const size_t pos, const int value)
{
	assert(pos < count);
	checkAndIncreaseCapacity();

	for (size_t i = count; i > pos; i--) {
		array[i] = array[i - 1];
	}
	array[pos] = value;
	count++;
}

void MyVector::pop()
{
	assert(!isEmpty());
	count--;
}

void MyVector::remove(const size_t pos)
{
	assert(pos < count);
	for (size_t i = pos + 1; i < count; i++) {
		array[i - 1] = array[i];
	}
	count--;
}

void MyVector::clear()
{
	count = 0;
}

int MyVector::get(const size_t pos) const
{
	assert(pos < count);
	return array[pos];
}

void MyVector::set(const size_t pos, const int value)
{
	assert(pos < count);
	array[pos] = value;
}

size_t MyVector::find(const int value) const
{
	for (size_t i = 0; i < count; i++) {
		if (array[i] == value) {
			return i;
		}
	}
	return VECTOR_VALUE_NOT_FOUND;
}
