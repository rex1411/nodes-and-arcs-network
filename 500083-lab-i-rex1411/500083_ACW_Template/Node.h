#pragma once
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Navigation;
class Arcs;

class Node
{




public:

	Node(const string& pNode, const int pRefNo, const double pX, const double pY);

	~Node(void);

	
	//getter and setters
	const double Getx()const;
	const double Gety()const;
	const string& GetName()const;
	const int GetRefNumber()const;


private:

	string Name;
	int RefNumber;
	double XCoord;
	double YCoord;

	

};



