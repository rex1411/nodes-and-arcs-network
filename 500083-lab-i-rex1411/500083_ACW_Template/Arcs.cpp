#include "Arcs.h"
#include "Node.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Navigation.h"
#include "ACW_Wrapper.h"
using namespace std;

Arcs::Arcs(const int pRefNo1, const int pRefNo2,const string& travel, const int dist)
{
	this->StartingNode = pRefNo1;
	this->Destination = pRefNo2;
	this->mode = travel;
	this->Distance = dist;
}

Arcs::~Arcs(void)
{
}

const string& Arcs::GetMode()const
{
	return mode;
}

const int Arcs::GetDes()const
{
	return Destination;
}

const int Arcs::GetStart()const
{
	return StartingNode;
}

const double Arcs::GetDistance()const
{
	return Distance;
}



