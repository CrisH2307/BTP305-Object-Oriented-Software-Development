//* ENUMERATIONS
/*
Unsigned Standard Integers
_ The different between unsigned and signed is that they only represent positive numbers
there by effectively extending the number of positive number they can represent

Type Inference
_ Using 'auto' keyword we can have the compiler infer what the type of a particular 
variable is being on the right operand at initalization
    auto x = 3.6 -> The type of x will be based on 3.6 so some sort of floating(or double)
_ Auto cant be used with array to determine their type as of yet

Pointer:
_ A pointer is a type that holds an address as its value. Every type has a associated ptr
type to go along with it.
    int - int*

    typedef long long int* lliptr;
    lliptr myptr = nullptr;

    typedef long long int lli;
    lli* myptr2 = nullptr;

Generic Pointer:
    i = static_cast<int*>(static_cast<void*>(c));
                |                   |
     Then cast the void     First cast the char
     ptr to an int ptr      ptr to a void ptr

Synonym Ptr: A synonym pointer type simplifies repeated definitions of the pointer type
     typedef unsigned long long int* ullint_ptr; 
     ullint_ptr p; // a pointer to ullint 


References:
_ Is an alias for an existing obj
    + lvalue : &
    -> Identifies an accessible region of memory
    + rvalue : &&
    -> Identifies an obj near the end of its lifetime, a temporary obj or subobj, a value not assiciated with an obj
    
_ Lvalue requires an initializer unless it:
+ Has external linkage
+ Is a class member within a class definition
+ Is a function parameter or a function return type

_ Rvalue identifies an obj that is less permanent, possibly temp


Range Based For-Loops:
_ A ranged based for loop is a nice improvement on a regular for loop in that it allows 
you to traverse through an array without need its size:

for (int i = 0; i < sizeof(x) / sizeof(int); ++i)
{
    cout << "reg-item: " << x[i] << endl;
}

for (auto& item : x)
{
    cout << "range item: " << item << endl;
}

Move Operators:
_ Move operators much like their naming will more simply move resoruce by copying the address
of the source, this eliminates the need for actual copying
        Classname(Classname&&); -  Playdoh(Playdoh&& src)
        Classname& operator=(Classname&&); - Playdoh& operator=(Playdoh&& src)
_ The && will denote that these functions work with Rvalues. They take Rvalue references
to the source obj and swap the addresses of it and the current obj

Anonymous Classes:
_ Are classes that dont have an identifier attached to their definition
_ They're used in the cases where you dont need to reference their typing and may only
need to use a small number of instances in a closed range
_ They use instance identifier following their definition to name the instances

Enumerations:
_ Enumerations or enums present a machanism to allow for using descriptive names in place of constant values
_ The inderlying type behind an enum is an int

Plain Enums:
    enum Type {symbolic_constant_1, symbolic_constant_2,...};
    enum Traffic_light {red, yellow, green};

Scoped Enums:
    enum class Type {symbolic_constant_1, symbolic_constant_2,...};
    enum class Traffic_light {red, yellow, green};

_ The difference between scoped enums and plain one that they will abide by the scope of the enums
and thus need to be resolved with their scope (scope resolution)
*/

class { // annoymous class
    double efficiency;

    public:
    void setEffi(double e)
    {
        efficiency = e;
    }
    int fuelCost(int distance)
    {
        return distance * efficiency;
    }
} engine;     //! We have a single instane of this unamed class called 'engine'


enum class Trafic_light  //Underlying enum types
{
    red = 1,
    yellow = 3,
    green = 6,
    orange = 12
};