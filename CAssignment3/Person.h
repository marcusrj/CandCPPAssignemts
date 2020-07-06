#include <string>
#include <iostream>

#ifndef _PERSON_H
#define _PERSON_H

using namespace std;


//defines a person with name address postcode and phone number
class Person{
	private:
		string name;
		string address;
		string postcode;
		string phoneNumber;	
	public:
		//Blank constructor
		Person();
		//Constructor that gets all the details passed in
		Person(string name, string address, string postcode, string phoneNumber);
 
 		//Mutator methods to allow the values of the private fields to be changed
		void setName(string newName);
		void setAddress(string NewAddress);
		void setPostcode(string newPostcode);
		void setPhoneNumber(string NewPhoneNumber);

		//Accessor Methods to return the values stored in the private fields
		string getName();
		string getAddress();
		string getPostcode();
		string getPhoneNumber();

		//Returns all the fields concatenated into one string
		string toString();
};
#endif