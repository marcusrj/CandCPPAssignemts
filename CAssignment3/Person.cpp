#include "Person.h"

using namespace std;

//Blank constructor
Person::Person()
{
	
}

//Constructor that gets all the details passed in
Person::Person(string name, string address, string postcode, string phoneNumber)
{
	this->setName(name);
	this->setAddress(address);
	this->setPostcode(postcode);
	this->setPhoneNumber(phoneNumber);
}

//Mutator to set the name
void Person::setName(string newName)
{
	name = newName;
}

//Accessor to return name
string Person::getName()
{
	return name;
}

//Mutator to set Address
void Person::setAddress(string newAddress)
{
	address = newAddress;
}

//Accessor to return Address
string Person::getAddress()
{
	return address;
}

//Mutator to set Postcode
void Person::setPostcode(string newPostcode)
{
	postcode = newPostcode;
}

//Accessor to return Postcode
string Person::getPostcode()
{
	return postcode;
}

//Mutator to set phonenumber
void Person::setPhoneNumber(string newPhoneNumber)
{
	phoneNumber = newPhoneNumber;
}

//Accessor to return phonenumber 
string Person::getPhoneNumber()
{
	return phoneNumber;
}

//Return the values of all fields concatenated into one string
string Person::toString()
{
	return name + " " + address + " " + postcode + " " + phoneNumber;
}

