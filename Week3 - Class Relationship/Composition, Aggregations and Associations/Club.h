// Aggregation
// Club.h
/*
Consider the relationship between a club and its members. The relationship is between the club and the names of its
members as illustrated below. The club has or may have members, but can exist without any. A member's name can be 
removed from its list of members before the club is disbanded and that name is not destroyed if the club is disbanded.

            Club <--- Name
*/
class Name;

constexpr int M { 50 };

class Club
{
    const Name* name[M]{};
    int m { 0 };
public:
    Club& operator+=(const Name&);
    Club& operator-=(const Name&);
    void display() const;
    //...
};