// Association
// association.cpp

#include "Course.h"
#include "Room.h"

void book(Course& c, Room& r) {
c.book(r);
r.book(c);
}

int main()
{
    Room t2108("T2108");
    Room t2109("T2109");
    Room t2110("T2110");

    Course btp105("Intro to Programming", 105);
    Course btp205("Intro to O-O Prg", 205);
    Course btp305("O-O Programming", 305);

    btp105.display();
    btp205.display();
    btp305.display();

    t2108.display();
    t2109.display();
    t2110.display();

    book(btp205, t2110);
    book(btp305, t2108);

    btp105.display();
    btp205.display();
    btp305.display();

    t2108.display();
    t2109.display();
    t2110.display();

    book(btp205, t2108);
    book(btp305, t2109);

    btp105.display();
    btp205.display();
    btp305.display();

    t2108.display();
    t2109.display();
    t2110.display();
}

/*
Output:
***** 105 Intro to Programming
***** 205 Intro to O-O Prg
***** 305 O-O Programming
T2108 available
T2109 available
T2110 available


***** 105 Intro to Programming
T2110 205 Intro to O-O Prg
T2108 305 O-O Programming
T2108 O-O Programming
T2109 available
T2110 Intro to O-O Programming


***** 105 Intro to Programming
T2108 205 Intro to O-O Prg
T2109 305 O-O Programming
T2108 Intro to O-O Programming
T2109 O-O Programming
T2110 available

*/