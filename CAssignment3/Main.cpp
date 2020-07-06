#include "hashtable.h"
#include <stdlib.h>

//initialise hashtable
HashTable* myHashTable = new HashTable();

//gets details of person from user, stores them, and adds them to table
void addNewPerson()
{
	//storage for persons details
	string name, address, postcode, phonenumber;

	//prompting user to enter details then reading each one in 
	cout << "Enter Name: " << endl;
	getline(cin, name);
	cout << "Enter Address: " << endl;
	getline(cin, address);
	cout << "Enter Postcode: " << endl;
	getline(cin, postcode);
	cout << "Enter Phone Number: " << endl;
	getline(cin, phonenumber);

	//create person with details
	Person* p = new Person(name, address, postcode, phonenumber);
	//store person in node
	ListNode* n = new ListNode(p);
	//add node to table
	myHashTable->addToTable(name,p);
}
//search for a person and tell user if they exist
void searchForPerson()
{
	//store name
	string name;
	//prompt user to enter name
	cout << "Enter Name of Person to search for" << endl;
	//read in name
	getline(cin, name);
	//if person was found tell user they exist
	if (myHashTable->getFromTable(name) != NULL)
	{
		cout << name << " was found." << endl;
	}
	//else tell user that person doesnt exist
	else
	{
		cout << name << " was not found." << endl;
	}
}
//delete a person based on name that was input
void removeAPerson()
{
	//prompt user to enter name of person to delete
	cout << "Enter Name of Person to Delete" << endl;
	//storage for name
	string name;
	//read in name
	getline(cin, name);
	//if person exists then delete them
	if (myHashTable->getFromTable(name) != NULL)
	{
		myHashTable->removeFromTable(name);
		//tell user that person was delete
		cout << name << " was deleted." << endl;
	}
	else
	{
		//else tell user that peron doesnt exist
		cout << name << " was not found so could not be deleted." << endl;
	}
}
//displays a person that the user inputs the name of (if they exist)
void displayAPerson()
{
	//store name
	string name;
	//prompt user to enter name
	cout << "Enter Name of Person to Display" << endl;
	//read input
	getline(cin, name);

	//if person is in table
	if (myHashTable->getFromTable(name) != NULL)
	{
		//get person
		Person* p = myHashTable->getFromTable(name);
		//display person
		cout << "Name: " + p->getName() <<endl;
		cout << "Address: " + p->getAddress() <<endl;
		cout << "Postcode: " + p->getPostcode() <<endl;
		cout << "Phone Number: " + p->getPhoneNumber() <<endl;
		//cout << p->toString() << endl;
	}
	else 
	{
		//tell user name not found
		cout << name + "was not found" <<endl;
	}

}

//main method
int main()
{
	//stores choice
	string choice = "0";

	//while choice isnt 6 (the quit option)
	while (choice != "6")
	{
		//print out a menu to the user
		cout << "=====================================" << endl;
		cout <<	"	1. Add new Person." 		 	 << endl;
		cout << "	2. Search for Person." 			 << endl;
		cout << "	3. Remove Person." 				 << endl;
		cout << "	4. Display a Person." 			 << endl;
		cout << "	5. Display All." 				 << endl;
		cout << "	6. Exit." 						 << endl;
		cout << "=====================================" << endl;

		//get choice from user
		getline(cin, choice);
		//call  different methods edpending on choice
		if (choice == "1")
		{
			addNewPerson();
		}
		else if (choice == "2")
		{			
			searchForPerson();
		}
		else if (choice == "3")
		{
			removeAPerson();
		}
		else if (choice == "4")
		{
			displayAPerson();
		}	
		else if (choice == "5")
		{
			myHashTable->displayAll();
		}	
		else if (choice == "6")
		{
			delete myHashTable;
			exit(0);
		}
		else
		{
			cout<<"Invalid choice."<<endl;
		}
	}
}