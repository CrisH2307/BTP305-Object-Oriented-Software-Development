#include <iostream>

using namespace std;

class Car
{

};

/*
Client tells me:
+ I have Car obj
+ I make a copy of my Car obj. I'm giving u the copy named Car1
+ Do whatever u want with the copy Car_1
*/
void travel(Car car_1)
{

}

/*
Client tells me:
+ I have Car obj
+ I'm lending you the original obj. U can access it under the name "car_2"
+ I'm still using that obj --> dont break it
*/
void travel(Car& car_2)
{

}

/*
Client tells me:
+ I have Car obj
+ I'm giving you the original obj. U can access it under the name "car_3"
+ Do whatever u want with the copy Car_3 --> I dont need it
*/
void travel(Car&& car_3)
{

}

int main()
{
    
}
