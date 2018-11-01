#include <iostream>
using namespace std;


class Odometer
{
private:
    double miles;
    double fuel_efficiency;

public:
    Odometer()
    {
        miles = 0;
        fuel_efficiency = 0;
    }

    void reset()
    {
        miles = 0; //to remove our data
        //fuel_efficiency = 0;
    }

    void setFuelEfficiency(double x) //to set fuel
    {
        fuel_efficiency = x;
    }

    void Milesdriven (double y) //to set miles
    {
        miles = y;
    }

    double print_gasgallon() //to calculate total
    {
        return miles/fuel_efficiency;
    }



};


int main()
{

    Odometer o1; //object
    o1.reset();
    o1.setFuelEfficiency(60);
    o1.Milesdriven(200);
    cout << "For your fuel-efficient small car:" << endl;
    cout << "When your fuel efficiency is 60 : "<< endl << endl;
    cout << "After 200 miles, " << o1.print_gasgallon() <<" gallons were used." << endl;
    o1.Milesdriven(80);
    cout << "After another 80 miles, " << o1.print_gasgallon() <<" gallons were used." << endl;

    cout << endl;



    return 0;
}
