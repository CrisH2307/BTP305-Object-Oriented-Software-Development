#ifndef NAME_H
#define NAME_H
// Composition - Name
// Name.h
/*
Consider the relationship between a Person class and a Name class illustrated below: every person has a name.

        Person <|--- Name

*/
class Name
{
    char* name { nullptr };
public:
    Name(const char*);
    Name(const Name&);

    Name& operator=(const Name&);
    ~Name();

    const char* get() const;
    void set(const char*);
};
#endif