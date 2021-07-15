#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "Node.h"
#include "Arcs.h"
#include "Navigation.h"
using namespace std;

class Node;
class Navigation;
class Arcs
{

public:
;
	Arcs(const int pRefNo1, const int pRefNo2, const string& travel, const int dist);
	~Arcs(void);
	//getters
	const string& GetMode()const;
	const int GetDes()const;
	const int GetStart()const;
	const double GetDistance()const;

	




private:

	string mode;
	int Destination;
	int StartingNode;
	double Distance;

};



