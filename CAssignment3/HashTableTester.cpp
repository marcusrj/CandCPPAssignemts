#include "HashTable.h"

int main()
{
	HashTable* myHashTable = new HashTable();

	Person* person[5]; 

	cout << "Adding 5 people there should be 2 collisions caused" << endl;
	person[0] = new Person("Barry Allen", "Star Labs", "ST1 2LB", "07234 658457");

	//These two will 100% collide due to them having the same total is all ascii values added
	person[1] = new Person("Bruce Wayne", "Wayne Manor", "GT2 7BM", "07523 343455");
	person[2] = new Person("Wruce Bayne", "Bayne Manor", "GT4 4TE", "07231 123256");
	//Same goes for these
	person[3] = new Person("Harry Potter", "The Cupboard under the stairs", "LW1 2HP", "07234 645645");
	person[4] = new Person("Parry Hotter", "1 Street Name", "ST1 1NM", "07123 456789");

	for(int i = 0; i<5; i++)
	{
		myHashTable->addToTable(person[i]->getName(),person[i]);
	}
	myHashTable->displayAll();

	cout << "Displaying All linked lists to show that collisions have happened..." << endl;
	myHashTable->displayListSizes();

}
