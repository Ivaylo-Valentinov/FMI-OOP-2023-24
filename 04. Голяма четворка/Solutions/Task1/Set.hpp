class Set {
    int* elements;

    int numElements;
    int capacity;

    void resize();
    void copy(int const* elements, int numElements, int capacity);

public:
    Set();
    Set(Set const& other);
    Set& operator= (Set const& other);
    ~Set();

    bool addElement(int const element);
    bool deleteElement(int const element);
    void setUnion(Set const& other);
    void setIntersection(Set const& other);
    void print();
};