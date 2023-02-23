#include <iostream>
using namespace std;


class vehicle
{
    string name;
    int* horsePower;

public:
    int maxSpeed = 0;
    vehicle() {
        name = " ";
        horsePower = new int;
    };
    /*
    virtual ~vehicle() {
        cout << "Destructor of vehicle class is called" << endl;
    }*/

    vehicle(string _name, int _horsePower);
    vehicle(const vehicle& object);        //copy constructor
    const string& getName() const;
    const int& getHorsePower() const;

    virtual void print() {
        cout << "This is vehicle" << endl;
    }
    virtual void setMaxSpeed() = 0;
};


vehicle::vehicle(string _name, int _horsePower)
{
    this->name = _name;
    this->horsePower = new int(_horsePower);
}


vehicle::vehicle(const vehicle& object)
{
    this->name = object.name;
    //this->horsePower=object.horsePower; //Wrong-Shallow Copy
    this->horsePower = new int(*object.horsePower);//Deep copy
    cout << "Copy constructor called" << endl;
}

const string& vehicle::getName() const
{
    return this->name;
}

const int& vehicle::getHorsePower() const
{
    return *this->horsePower;
}

class Car : public vehicle
{
public:
    void print() {
        cout << "This is car" << endl;
    }
    /*
    ~Car() {
        cout << "Destructor of Car class is called" << endl;

    }*/

    void setMaxSpeed() {
        maxSpeed = 320;
    }

};

class Bus :
    public vehicle
{
public:
    void print() {
        cout << "This is bus" << endl;
    }
    /*
    ~Bus() {
        cout << "Destructor of bus class is called" << endl;

    }
    */
    void setMaxSpeed() {
        maxSpeed = 180;
    }

};






int main() {
    /*    COPY CONSTRUCTOR    */
    /*
    vehicle v1("AUDI A4", 2000);
    vehicle v2(v1);	//copy constructor
    vehicle v3 = v1; //copy constructor


    cout << "Name: " << v1.getName() << ", " << "Horsepower: " << v1.getHorsePower() << endl;
    cout << "Name: " << v2.getName() << ", " << "Horsepower: " << v2.getHorsePower() << endl;
    cout << "Name: " << v3.getName() << ", " << "Horsepower: " << v3.getHorsePower() << endl;
    cout << "\n" << endl;
    */
    /*      VIRTUAL FUNCTION     */

    Car car1;
    Bus bus1;
    vehicle* vehicle1 = &car1;
    vehicle* vehicle2 = &bus1;
    vehicle1->print();
    vehicle2->print();
    vehicle1->setMaxSpeed();
    cout << "Max speed of the car: " << vehicle1->maxSpeed << endl;
    vehicle2->setMaxSpeed();
    cout << "Max speed of the car: " << vehicle2->maxSpeed << endl;
    //delete vehicle1;
    //delete vehicle2;

}