void sayHello();  // Declaration

//int g_data = 10; // Definition

extern int g_data; // Allows me declare without define --> Declaration

const int SIZE = 10; // Definition

// Function and variables have external linkage by default
// Constant have internal linkage be default

class O  // Classes do not in the first stage of compile
{
    int data;
};