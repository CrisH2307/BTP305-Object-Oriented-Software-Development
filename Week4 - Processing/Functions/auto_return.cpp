// Trailing Return - Enumeration within a class
// auto_return.cpp

/*
Consider the function get() in the following program. When the compiler starts processing its definition the return type 
(TicketType) is unknown. TicketType is defined in class scope. Initially, the compiler is unaware that the return type is
defined inside the Ticket class. Only after the compiler becomes aware from the identifier Ticket::get() that the function 
is a member of the Ticket class can accept the return type

! Without auto and the trailing return-type in the definition of get(), we need to scope the 
! return type (TicketType) by adding the class name; that is, to write:
?         Ticket::TicketType Ticket::get() const { return ticketType; }
instead of:
?         TicketType Ticket::get() const { return ticketType; }
*/

#include <iostream>

class Ticket
{
public:
    enum class TicketType { Adult, Child };

    void set(TicketType tt);
    TicketType get() const;

private:
    TicketType ticketType;
};

std::ostream& operator<<(std::ostream& os, const Ticket::TicketType& tt)
{
    const char* label = nullptr;
    switch(tt)
    {
    case Ticket::TicketType::Adult:
        label = "Adult Ticket";
        break;
    case Ticket::TicketType::Child:
        label = "Child Ticket";
        break;
    default:
        label = "No Ticket";
    }
    os << label;
    return os;
}

void Ticket::set(TicketType tt) { ticketType = tt; }

auto Ticket::get() const -> TicketType { return ticketType; }

int main ()
{
    Ticket a, b;

    a.set(Ticket::TicketType::Adult);
    b.set(Ticket::TicketType::Child);

    std::cout << a.get() << std::endl;
    std::cout << b.get() << std::endl;
}

/*
Output:

Adult Ticket
Child Ticket

*/
