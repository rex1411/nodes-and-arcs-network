#pragma once
#include <fstream>
#include <string>
#include "Navigation.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Node.h"
#include "ACW_Wrapper.h"
#include <vector>
#include "Arcs.h"

class Node;
class Arcs;

class Navigation
{
	std::ofstream _outFile;



public:

	Navigation();
	~Navigation();

	bool BuildNetwork(const std::string& fileNamePlaces, const std::string& fileNameLinks);
	bool ProcessCommand(const std::string& commandString);
	bool ProcessMaxDist();
	bool ProcessMaxLink();
	bool ProcessFindDist(const int ref1, const int ref2);
	bool ProcessFindNeighbour(const int ref1);
	bool ProcessCheckRail(vector<int>& refs);
	bool ProcessCheckShip(vector<int>& refs);
	bool ProcessCheckCar(vector<int>& refs);
	bool ProcessCheckBike(vector<int>& refs); 
	bool ProcessCheckFoot(vector<int>& refs);
	bool ProcessCheckBus(vector<int>& refs);
	bool ProcessFindRouteRail(const int ref1, const int ref2);
	bool ProcessFindRouteShip(const int ref1, const int ref2);
	bool ProcessFindRouteBus(const int ref1, const int ref2);
	bool ProcessFindRouteCar(const int ref1, const int ref2);
	bool ProcessFindRouteBike(const int ref1, const int ref2);
	bool ProcessFindRouteFoot(const int ref1, const int ref2);

	Node* FindNodes(const int a);
	double calcDist(const int a, const int b);
	void remove(vector<int>& v)const;

private:
	vector <Node*> nodelist;
	vector<Arcs*> ArcList;
};