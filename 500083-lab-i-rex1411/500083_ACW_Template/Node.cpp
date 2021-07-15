#include "Node.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Navigation.h"
#include "ACW_Wrapper.h"
using namespace std;




Node::Node(const string& pNode, const int pRefNo, const double pX, const double pY)
{
	// add the string from up into the node
	this->Name = pNode;
	this->RefNumber = pRefNo;
	this->XCoord = pX;
	this->YCoord = pY;



}

Node::~Node()
{
}

const double Node::Getx()const
{
	return XCoord;
}
const double Node::Gety()const
{
	return YCoord;
}
const string& Node::GetName()const
{
	return Name;
}
const int Node::GetRefNumber()const
{
	return RefNumber;
}
