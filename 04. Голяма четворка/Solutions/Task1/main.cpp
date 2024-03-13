#include <iostream>
#include "Set.hpp"

int main() {
    Set a, b, c;

    for(int i = 0; i < 15; i++) {
        a.addElement(i);
    }

    for(int i = 10; i < 20; i++) {
        b.addElement(i);
    }

    for(int i = 17; i < 26; i++) {
        c.addElement(i);
    }

    a.print();
    b.print();

    a.deleteElement(9);       
    a.print();

    a.setIntersection(b);
    a.print();

    b.setUnion(c);
    b.print();

    return 0;
}