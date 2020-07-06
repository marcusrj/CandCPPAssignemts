#include <iostream>
#include <array>
using namespace std;

class CA {




public:
	int oldGen [];
	int newGen [];
	int rule[] ;
	CA();
void setRule();
	void getNewGen();
	void setFirstGen();
	int calcNewVal(int left, int middle, int right);
	void printGen();
	
};
