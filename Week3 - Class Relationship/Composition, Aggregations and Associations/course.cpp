// Association
// Course.cpp

#include <iostream>
#include "course.h"
#include "room.h"

Course::Course(const char* n, int c) : name{n}, code{c} {}

void Course::book(Room& r)
{
    if (room) room->release();
    room = &r;
}

void Course::release()
{
    room = nullptr;
}

const char* Course::get() const
{
    return name.get();
}

void Course::display() const
{
    std::cout << (room ? room->get() : "*****")
              << ' ' << code << ' ' << name.get()
              << std::endl;
}
//...