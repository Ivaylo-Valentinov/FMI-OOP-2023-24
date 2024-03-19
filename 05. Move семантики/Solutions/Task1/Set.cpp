#include "Set.hpp"
#include <iostream>
int const INITIAL_CAPACITY = 10;

void Set::copy(int const* elements, int numElements, int capacity) {
    this->capacity = capacity;
    this->numElements = numElements;

    if (this->elements != nullptr) {
        delete[] this->elements;
    }
    this->elements = new int [this->capacity];
    for(int i = 0; i < this->numElements; i++) {
        this->elements[i] = elements[i];
    }
}

Set::Set() {
    this->numElements = 0;
    this->capacity = INITIAL_CAPACITY;
    this->elements = new int[this->capacity];
}


Set::Set(Set const& other) {
    this->copy(other.elements, other.numElements, other.capacity);
}

Set& Set::operator= (Set const& other) {
    if (this != &other) {
        this->copy(other.elements, other.numElements, other.capacity);
    }

    return *this;
}

Set::~Set() {
    delete[] this->elements;
}

void Set::resize() {
    this->capacity *= 2;
    int* copyElements = new int[this->capacity];

    for(int i = 0; i < this->numElements; i++) {
        copyElements[i] = this->elements[i];
    }

    delete[] this->elements;
    this->elements = copyElements;
}

bool Set::addElement(int const element) {
    if(this->numElements == this->capacity) {
        this->resize();
    }

    for(int i = 0; i < this->numElements; i++) {
        if(this->elements[i] == element) {
            return false;
        }
    }
    this->elements[this->numElements] = element;
    this->numElements++;
    return true;    
}


bool Set::deleteElement(int const element) {
    for(int i = 0; i < this->numElements; i++) {
        if(this->elements[i] == element) {
            for(int j = i + 1; j < this->numElements; j++) {
                this->elements[j - 1] = this->elements[j]; 
            }
            this->numElements--;
            return true;
        }
    }
    return false;  
}
void Set::setUnion(Set const& other) {
    for(int i = 0; i < other.numElements; i++) {
        this->addElement(other.elements[i]);
    }
}
void Set::setIntersection(Set const& other) {
    for(int i = 0; i < this->numElements; i++) {
        int j = 0;
        while(j < other.numElements && this->elements[i] != other.elements[j]) {
            j++;
        }
        if(j == other.numElements) {
            this->deleteElement(this->elements[i]);
            i--;
        }
    }
}
void Set::print() {
    for(int i = 0; i < this->numElements; i++) {
        std::cout << this->elements[i] << " ";
    }
    std::cout << std::endl;
}

void Set::move(Set&& other) {
    this->numElements = other.numElements;
    this->capacity = other.capacity;

    if (this->elements != nullptr) {
        delete[] this->elements;
    }
    this->elements = other.elements;

    other.numElements = 0;
    other.capacity = 0;
    other.elements = nullptr;
}
void Set::move(Set&& other) {
    this->numElements = other.numElements;
    this->capacity = other.capacity;

    if (this->elements != nullptr) {
        delete[] this->elements;
    }
    this->elements = other.elements;

    other.numElements = 0;
    other.capacity = 0;
    other.elements = nullptr;
}

Set::Set(Set&& other) {
    this->move(std::move(other));
}

Set& Set::operator=(Set&& other) {
    if (this != &other) {
        this->move(std::move(other));
    }

    return *this;
}
