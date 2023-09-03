// Association
// Course.h
/*
Consider the relationship between a course and a room in a college. The course uses the room and the room is booked for the course for
a certain period. , but both exist independently of one another. A room can be booked for a course and a course can be assigned to a
room. Neither is destroyed when the other is destroyed.
                Course ---- Room
*/

#include "Name.h"
class Room;

class Course
{
    Name name;
    int code;
    Room* room { nullptr };

public:
    Course(const char*, int);

    void book(Room&);
    void release();
    const char* get() const;
    void display() const;
    //...
};