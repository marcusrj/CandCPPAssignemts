#include <iostream>
//#include "Test.h"
#include <array>
#include <string>
#include <bitset>
using namespace std;

class CA{



private:
	//int oldGen [];
	//int newGen [];
	//int rule[] ;


public:
	
	CA();
	void setRule();
	void getNewGen();
	void setFirstGen();
	int calcNewVal(int left, int middle, int right);
	void printGen();
	std::string int_to_bin(int number)
	
};





	int oldGen [40];
	int newGen [40];
	int rule[8]={0,1,1,0,1,1,1,0};
	
	CA::CA()
	{
		
	}
	
	

	void CA::setRule()
	{
		cout << "Enter the rule you would like (0-255)";
		int newRule;
		cin >> newRule;
		cout<< newRule;
		std::string binary = std::bitset<8>(128).to_string();
		
		//std::ostringstream os;

		//os << newRule;
		//std::string binary = os.str();
		
		cout << binary;
		for (int i = 0; i < 8; i++)
		{
			rule[i] = binary[i] - 48;
			//newRule = newRule / 10;
			//cout << newRule << " ";
			//cout << rule[i];
		}
		for (int i = 0; i < 8; i++)
		{
			cout << rule[i];
		}
	
	
	}
	
	
	void CA::setFirstGen()
	{
		
		for (int i = 0; i<40; i++)
		{
			if (i == 20)
			{
				oldGen[i]=1;
				
			}
			else
			{
				oldGen[i]=0;
				
			}
			
		}
		//CA::printGen();
	}

	void CA::printGen()
	{
		
		for (int i = 0; i<40;i++)
		{
			if (oldGen[i] == 1)
			{
				cout << "\u25A0 ";
				//cout << "#";
			}
			else
			{
				cout << "\u25A1 ";
				//cout << ".";
			}
			
		}
		cout << "l" << endl;
	}

	int CA::calcNewVal(int left, int middle, int right)
	{
		
		//int rule[8]={0,0,0,1,1,1,1,0};
    		if (left == 1 && middle == 1 && right == 1) 
		{
			return rule[0];
		}
    		else if (left == 1 && middle == 1 && right == 0) 
		{
			return rule[1];
		}
    		else if (left == 1 && middle == 0 && right == 1) 
		{
			return rule[2];
		}
    		else if (left == 1 && middle == 0 && right == 0) 
		{
			return rule[3];
		}
   		else if (left == 0 && middle == 1 && right == 1) 
		{
			return rule[4];
		}
   		else if (left == 0 && middle == 1 && right == 0) 
		{
			return rule[5];
		}
   		else if (left == 0 && middle == 0 && right == 1) 
		{
			return rule[6];
		}
    		else if (left == 0 && middle == 0 && right == 0) 
		{
			return rule[7];
		}
		else
		{
    		//	return 0;
		}
	}

	void CA::getNewGen()
	{

		int left, middle, right, newVal;

		for (int i = 0; i <= 40; i++)
		{
			if (i == 0)
			{
				left = oldGen[40];
				middle = oldGen[i];
				right = oldGen[i+1];
			}
			else if (i == 40)
			{
				left = oldGen[i-1];
				middle = oldGen[i];
				right = oldGen[0];
			}
			else
			{
				left = oldGen[i-1];
				middle = oldGen[i];
				right = oldGen[i+1];		
			}
			
			newVal = CA::calcNewVal(left,middle,right);
			newGen[i] = newVal;
			//cout << newVal;
	}
		
		//for (int i=0;i<8;i++){
		//	cout<<rule[i];
		//}
		//	cout<<""<<endl;
		
		

		for (int i = 0; i < 40; i++)
		{
			oldGen[i] = newGen[i];
		}


	}


	int main ()
	{
		CA *myCA = new CA();
		cout << "a" << endl;
		myCA->setRule();
		myCA->setFirstGen();
		for (int i = 0; i<50; i++)
		{
		
		myCA->printGen();
		myCA->getNewGen();
		
		
		}
		cout << "l" << endl;


		delete myCA;
		return 0;
	}
	


