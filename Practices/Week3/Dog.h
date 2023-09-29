#include "Animal.h"
#include <string>

class Dog : public Animal
{
    std::string m_name = "Tokuda";
public:
    void move() override;
    void eat();
};