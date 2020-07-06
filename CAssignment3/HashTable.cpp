#include "HashTable.h"

//constructor
HashTable::HashTable()
{
	//initialises all 20 linked list
	for (int i = 0; i < 20; i++)
	{
		HashArray[i] = new LinkedList();
	}

}	
//destructor
HashTable::~HashTable()
{
	//deletes all to linked lists
	for (int i = 0; i<20; i++)
	{
		delete HashArray[i];
	}
}
//hashes the string input and returns an int
int HashTable::hash(string input)
{
	int hash = 0;
	for (int i = 0; i<input.length(); i++)
	{
		hash = hash + input[i];
	}
	return hash % 20;
}
//adds a person to the table
void HashTable::addToTable(string key, Person* value)
{
	//hash the key and store in n
	int n = hash(key);
	//store person in a listnode
	ListNode* node = new ListNode(value);
	//add node to linked list that matches the hashed value
	HashArray[n]->addToEnd(node);
}
//returns a person from the table (returns null if not found)
Person* HashTable::getFromTable(string key)
{
	//hashes the key
	int n = hash(key);
	//if person is in list
	if (HashArray[n]->contains(key) != NULL)
	{
		//call contains method to check get person
		return HashArray[n]->contains(key);
	}
	else
	{
		return NULL;
	}
}
//remove a person whos name matches the one passed in, if they are in the table
void HashTable::removeFromTable(string key)
{
	ListNode* temp = new ListNode(getFromTable(key));
	HashArray[hash(key)]->deleteByName(temp);
}
//display all people stored in the table
void HashTable::displayAll()
{
	ListNode* temp = NULL;
	for (int i = 0; i<20; i++)
	{
		//reset temp to be null
		temp = NULL;
	
		if(HashArray[i]->getHead()==NULL) 
		{
		
		}
		else
		{
			temp = HashArray[i]->getHead();
		}
		//if temp isnt null
		if (temp != NULL)
		{
			//Print data 
			cout << "Name: " << temp->getData()->getName() <<endl;
			cout << "Address: " << temp->getData()->getAddress() <<endl;
			cout << "Postcode: " << temp->getData()->getPostcode() <<endl;
			cout << "Phone Number: " << temp->getData()->getPhoneNumber() <<endl;
			cout << "" << endl;

			while (temp->getNext() != NULL)
			{
				//Print data
				cout << "Name: " + temp->getNext()->getData()->getName() <<endl;
				cout << "Address: " + temp->getNext()->getData()->getAddress() <<endl;
				cout << "Postcode: " + temp->getNext()->getData()->getPostcode() <<endl;
				cout << "Phone Number: " + temp->getNext()->getData()->getPhoneNumber() <<endl;
				cout << "" << endl;
				//set temp to be next
				temp = temp->getNext();
			}
		}	
	} 
}
//display the sizes of all 20 linked lists
void HashTable::displayListSizes()
{
	for (int i = 0; i<20; i++)
	{	
		//Print the size
		cout << "List"<< i <<":" << HashArray[i]->getSize() << endl;
	}
}
