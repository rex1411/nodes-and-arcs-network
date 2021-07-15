#include "Navigation.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Node.h"
#include "ACW_Wrapper.h"
#include <algorithm>
using namespace std;

Navigation::Navigation() : _outFile("Output.txt")
{
}

Navigation::~Navigation()
{
}

bool Navigation::ProcessCommand(const string& commandString)
{
	istringstream inString(commandString);
	string command;
	inString >> command;

	// Add your code here
	int ref1, ref2, ref3;
	if (command == "MaxDist") {
		return ProcessMaxDist();
	}
	else if (command == "MaxLink")
	{
		return ProcessMaxLink();
	}
	else if (command == "FindDist")
	{

		inString >> ref1;
		inString >> ref2;
		return ProcessFindDist(ref1, ref2);
	}
	else if (command == "FindNeighbour")
	{
		inString >> ref3;
		return ProcessFindNeighbour(ref3);
	}
	else if (command == "Check")
	{
		string type;
		inString >> type;

		if (type == "Rail")
		{
			vector<int> references;
			while (!inString.eof())
			{
				int tmp;
				inString >> tmp;
				references.push_back(tmp);
			}
			return ProcessCheckRail(references);
		}
		else if (type == "Ship")
		{
			vector<int> references;
			while (!inString.eof())
			{
				int tmp;
				inString >> tmp;
				references.push_back(tmp);
			}
			return ProcessCheckShip(references);
		}
		else if (type == "Bus")
		{
			vector<int> references;
			while (!inString.eof())
			{
				int tmp;
				inString >> tmp;
				references.push_back(tmp);
			}
			return ProcessCheckBus(references);
		}
		else if (type == "Car")
		{
			vector<int> references;
			while (!inString.eof())
			{
				int tmp;
				inString >> tmp;
				references.push_back(tmp);
			}
			return ProcessCheckCar(references);
		}
		else if (type == "Bike")
		{
			vector<int> references;
			while (!inString.eof())
			{
				int tmp;
				inString >> tmp;
				references.push_back(tmp);
			}
			return ProcessCheckBike(references);
		}
		else if (type == "Foot")
		{
			vector<int> references;
			while (!inString.eof())
			{
				int tmp;
				inString >> tmp;
				references.push_back(tmp);
			}
			return ProcessCheckFoot(references);
		}
		else
		{
			return false;
		}

	}
	else if (command == "FindRoute")
	{
		string type;
		inString >> type;
		if (type == "Rail") 
		{
			int ref1, ref2;
			inString >> ref1;
			inString >> ref2;
			return ProcessFindRouteRail(ref1, ref2);
		}
		if (type == "Ship")
		{
			int ref1, ref2;
			inString >> ref1;
			inString >> ref2;
			return ProcessFindRouteShip(ref1, ref2);
		}
		if (type == "Bus")
		{
			int ref1, ref2;
			inString >> ref1;
			inString >> ref2;
			return ProcessFindRouteBus(ref1, ref2);
		}
		if (type == "Car")
		{
			int ref1, ref2;
			inString >> ref1;
			inString >> ref2;
			return ProcessFindRouteCar(ref1, ref2);
		}
		if (type == "Bike")
		{
			int ref1, ref2;
			inString >> ref1;
			inString >> ref2;
			return ProcessFindRouteBike(ref1, ref2);
		}
		if (type == "Foot")
		{
			int ref1, ref2;
			inString >> ref1;
			inString >> ref2;
			return ProcessFindRouteFoot(ref1, ref2);
		}

	}
	else if (command == "FindRoute Ship")
	{

	}
	else if (command == "FindShortestRoute Rail")
	{

	}
	else if (command == "FindShortestRoute Ship")
	{

	}

	return false;
}

bool Navigation::ProcessMaxDist()
{
	string nodename1 = "";
	string nodename2 = "";
	double x = 0;
	try {


		for (int i = 0; i < nodelist.size(); i++) {
			for (int j = 1; j < nodelist.size(); j++) {
				double const distance = sqrt(pow(nodelist[i]->Getx() - nodelist[j]->Getx(), 2) + pow(nodelist[i]->Gety() - nodelist[j]->Gety(), 2));
				if (x < distance) {
					x = distance;
					nodename1 = nodelist[i]->GetName();
					nodename2 = nodelist[j]->GetName();
				}

			}

		}
		char* const cstr = &nodename1[0];
		char* const cstr1 = &nodename2[0];
		string num = to_string(x);
		char* const cstr2 = &num[0];
		string const s = "maxDist";

		if (_outFile.is_open()) {
			_outFile << s;
			_outFile.put('\n');
			_outFile.write(cstr, nodename1.size());
			_outFile.put(',');
			_outFile.write(cstr1, nodename2.size());
			_outFile.put(',');
			_outFile.write(cstr2, num.size() - 3);
			_outFile.put('\n');
			_outFile.put('\n');
		}
		return true;
	}
	catch (const exception& exc)
	{
		return false;
	}
}

bool Navigation::ProcessMaxLink()
{
	int node1 = 0;
	int node2 = 0;
	double x = 0;
	try
	{
		for (int i = 0; i < ArcList.size(); i++)
		{
			double const nowdist = ArcList[i]->GetDistance();
			if (nowdist > x)
			{
				x = nowdist;
				node1 = ArcList[i]->GetStart();
				node2 = ArcList[i]->GetDes();

			}
		}
		string n1 = to_string(node1);
		string n2 = to_string(node2);
		char* const cstr = &n1[0];
		char* const cstr1 = &n2[0];
		string num = to_string(x);
		char* const cstr2 = &num[0];
		string const s = "MaxLink";

		if (_outFile.is_open()) {
			_outFile << s;
			_outFile.put('\n');
			_outFile.write(cstr, n1.size());
			_outFile.put(',');
			_outFile.write(cstr1, n2.size());
			_outFile.put(',');
			_outFile.write(cstr2, num.size() - 3);
			_outFile.put('\n');
			_outFile.put('\n');
		}
		return true;
	}
	catch (const exception& exc)
	{
		return false;
	}
}

bool Navigation::ProcessFindDist(const int ref1, const int ref2)
{
	try
	{
		int const NodeRef1 = ref1;
		int const NodeRef2 = ref2;
		const Node* const node1 = FindNodes(NodeRef1);
		const Node* const node2 = FindNodes(NodeRef2);
		double const distance = sqrt(pow(node1->Getx() - node2->Getx(), 2) + pow(node1->Gety() - node2->Gety(), 2));

		string n1 = node1->GetName();
		string n2 = node2->GetName();
		char* const cstr = &n1[0];
		char* const cstr1 = &n2[0];
		string num = to_string(distance);
		char* const cstr2 = &num[0];
		string const s = "FindDist";

		if (_outFile.is_open()) {
			_outFile << s;
			_outFile.put('\n');
			_outFile.write(cstr, n1.size());
			_outFile.put(',');
			_outFile.write(cstr1, n2.size());
			_outFile.put(',');
			_outFile.write(cstr2, num.size() - 3);
			_outFile.put('\n');
			_outFile.put('\n');
		}
		return true;
	}
	catch (const exception& exc)
	{
		return false;
	}

}

bool Navigation::ProcessFindNeighbour(const int ref1)
{
	try {
		int const NodeRef1 = ref1;
		string const name = "Find Neighbour ";
		if (_outFile.is_open()) {
			_outFile << name;
			_outFile << NodeRef1;
			_outFile << '\n';
		}
		for (int i = 0; i < ArcList.size(); i++) {
			if (NodeRef1 == ArcList[i]->GetStart())
			{
				int const NodeRef2 = ArcList[i]->GetDes();
				if (_outFile.is_open()) {
					_outFile << NodeRef2;
					_outFile << '\n';
				}
			}
			if (NodeRef1 == ArcList[i]->GetDes())
			{
				int const NodeRef2 = ArcList[i]->GetStart();
				if (_outFile.is_open()) {
					_outFile << NodeRef2;
					_outFile << '\n';
				}
			}
		}
		_outFile << '\n';
	}
	catch (const exception& exc) {
		return false;
	}

}

bool Navigation::ProcessCheckRail(vector<int>& refs)
{
	try
	{

		_outFile << "Check Rail ";
		for (int z = 0; z < refs.size(); z++)
		{
			_outFile << refs[z];
			_outFile << ' ';
		}
		_outFile << "\n";

		for (int i = 0; i < refs.size() - 1; i++)
		{
			bool arcfound = false;

			for (int y = 0; y < ArcList.size(); y++)
			{
				if (refs[i] == ArcList[y]->GetStart() && refs[i + 1] == ArcList[y]->GetDes())
				{
					arcfound = true;
					int const start = ArcList[y]->GetStart();
					int const end = ArcList[y]->GetDes();
					_outFile << start << ',' << end;
					if (ArcList[y]->GetMode() == "Rail")
					{

						_outFile << ',' << "PASS";
						_outFile << "\n";
					}
					else {
						y = ArcList.size() + 1;
						i = refs.size() + 1;
						_outFile << ',' << "FAIL";
					}
				}
				else if (refs[i + 1] == ArcList[y]->GetStart() && refs[i] == ArcList[y]->GetDes())
				{
					arcfound = true;
					int const start = ArcList[y]->GetDes();
					int const end = ArcList[y]->GetStart();
					_outFile << start << ',' << end;
					if (ArcList[y]->GetMode() == "Rail")
					{

						_outFile << ',' << "PASS";
						_outFile << "\n";
					}
					else {
						y = ArcList.size() + 1;
						i = refs.size() + 1;
						_outFile << ',' << "FAIL";
					}
				}
	
			}
			if (arcfound == false)
			{
				int const start = refs[i];
				int const end = refs[i + 1];
				_outFile << start << ',' << end;
				_outFile << ',' << "FAIL";
				_outFile << "\n";
				i = refs.size() + 1;
				break;
			}


		}
		_outFile << "\n";

	}
	catch (const exception& exc)
	{
		return false;
	}


}

bool Navigation::ProcessCheckShip(vector<int>& refs)
{
	try
	{

		_outFile << "Check Ship ";
		for (int z = 0; z < refs.size(); z++)
		{
			_outFile << refs[z];
			_outFile << ' ';
		}
		_outFile << "\n";

		for (int i = 0; i < refs.size() - 1; i++)
		{
			bool arcfound = false;
			
				for (int y = 0; y < ArcList.size(); y++)
				{
					if (refs[i] == ArcList[y]->GetStart() && refs[i + 1] == ArcList[y]->GetDes())
					{
						arcfound = true;
						int const start = ArcList[y]->GetStart();
						int const end = ArcList[y]->GetDes();
						_outFile << start << ',' << end;
						if (ArcList[y]->GetMode() == "Ship")
						{
							_outFile << ',' << "PASS";
							_outFile << "\n";

						}
						else {
							y = ArcList.size() + 1;
							i = refs.size() + 1;
							_outFile << ',' << "FAIL";
							_outFile << "\n";
						}
					}
					else if (refs[i + 1] == ArcList[y]->GetStart() && refs[i] == ArcList[y]->GetDes())
					{
						arcfound = true;
						int const start = ArcList[y]->GetDes();
						int const end = ArcList[y]->GetStart();
						_outFile << start << ',' << end;
						if (ArcList[y]->GetMode() == "Ship")
						{
							_outFile << ',' << "PASS";
							_outFile << "\n";

						}
						else {
							y = ArcList.size() + 1;
							i = refs.size() + 1;
							_outFile << ',' << "FAIL";
							_outFile << "\n";
						}
					}

				}
				if (arcfound == false)
				{
					int const start = refs[i];
					int const end = refs[i + 1];
					_outFile << start << ',' << end;
					_outFile << ',' << "FAIL";
					_outFile << "\n";
					i = refs.size() + 1;
					break;
				}
			

		}
		_outFile << "\n";

	}
	catch (const exception& exc)
	{
		return false;
	}
}

bool Navigation::ProcessCheckCar(vector<int>& refs)
{
	try
	{

		_outFile << "Check Car ";
		for (int z = 0; z < refs.size(); z++)
		{
			_outFile << refs[z];
			_outFile << ' ';
		}
		_outFile << "\n";

		for (int i = 0; i < refs.size() - 1; i++)
		{
			bool arcfound = false;
			for (int y = 0; y < ArcList.size(); y++)
			{
				if (refs[i] == ArcList[y]->GetStart() && refs[i + 1] == ArcList[y]->GetDes())
				{
					arcfound = true;
					int const start = ArcList[y]->GetStart();
					int const end = ArcList[y]->GetDes();
					_outFile << start << ',' << end;
					if (ArcList[y]->GetMode() == "Ship" || ArcList[y]->GetMode() == "Bus" || ArcList[y]->GetMode() == "Car")
					{

						_outFile << ',' << "PASS";
						_outFile << "\n";
					}
					else {
						y = ArcList.size() + 1;
						i = refs.size() + 1;
						_outFile << ',' << "FAIL";
					}
				}
				else if (refs[i + 1] == ArcList[y]->GetStart() && refs[i] == ArcList[y]->GetDes())
				{
					arcfound = true;
					int const start = ArcList[y]->GetDes();
					int const end = ArcList[y]->GetStart();
					_outFile << start << ',' << end;
					if (ArcList[y]->GetMode() == "Ship" || ArcList[y]->GetMode() == "Bus" || ArcList[y]->GetMode() == "Car")
					{

						_outFile << ',' << "PASS";
						_outFile << "\n";
					}
					else {
						y = ArcList.size() + 1;
						i = refs.size() + 1;
						_outFile << ',' << "FAIL";
					}
				}


			}
			if (arcfound == false)
			{
				int const start = refs[i];
				int const end = refs[i + 1];
				_outFile << start << ',' << end;
				_outFile << ',' << "FAIL";
				_outFile << "\n";
				i = refs.size() + 1;
				break;
			}

		}
		_outFile << "\n";

	}
	catch (const exception& exc)
	{
		return false;
	}
}

bool Navigation::ProcessCheckBike(vector<int>& refs)
{
	try
	{

		_outFile << "Check Bike ";
		for (int z = 0; z < refs.size(); z++)
		{
			_outFile << refs[z];
			_outFile << ' ';
		}
		_outFile << "\n";
		for (int i = 0; i < refs.size() - 1; i++)
		{
			bool arcfound = false;
			for (int y = 0; y < ArcList.size(); y++)
			{
				if (refs[i] == ArcList[y]->GetStart() && refs[i + 1] == ArcList[y]->GetDes())
				{
					arcfound = true;
					int const const start = ArcList[y]->GetStart();
					int const const end = ArcList[y]->GetDes();
					_outFile << start << ',' << end;
					if (ArcList[y]->GetMode() == "Ship" || ArcList[y]->GetMode() == "Bus" || ArcList[y]->GetMode() == "Car" || ArcList[y]->GetMode() == "Rail")
					{

						_outFile << ',' << "PASS";
						_outFile << "\n";
					}
					else {
						y = ArcList.size() + 1;
						i = refs.size() + 1;
						_outFile << ',' << "FAIL";
					}
				}
				else if (refs[i + 1] == ArcList[y]->GetStart() && refs[i] == ArcList[y]->GetDes())
				{
					arcfound = true;
					int const start = ArcList[y]->GetDes();
					int const end = ArcList[y]->GetStart();
					_outFile << start << ',' << end;
					if (ArcList[y]->GetMode() == "Ship" || ArcList[y]->GetMode() == "Bus" || ArcList[y]->GetMode() == "Car" || ArcList[y]->GetMode() == "Rail")
					{

						_outFile << ',' << "PASS";
						_outFile << "\n";
					}
					else {
						y = ArcList.size() + 1;
						i = refs.size() + 1;
						_outFile << ',' << "FAIL";
					}
				}

			}
			if (arcfound == false)
			{
				int const start = refs[i];
				int const end = refs[i + 1];
				_outFile << start << ',' << end;
				_outFile << ',' << "FAIL";
				_outFile << "\n";
				i = refs.size() + 1;
				break;
			}


		}
		_outFile << "\n";

	}
	catch (const exception& exc)
	{
		return false;
	}
}

bool Navigation::ProcessCheckFoot(vector<int>& refs)
{
	try
	{

		_outFile << "Check Foot ";

		for (int z = 0; z < refs.size(); z++)
		{
			_outFile << refs[z];
			_outFile << ' ';
		}
		_outFile << "\n";

		for (int i = 0; i < refs.size() - 1; i++)
		{
			bool arcfound = false;

			for (int y = 0; y < ArcList.size(); y++)
			{
				if (refs[i] == ArcList[y]->GetStart() && refs[i + 1] == ArcList[y]->GetDes())
				{
					arcfound = true;
					int const start = ArcList[y]->GetStart();
					int const end = ArcList[y]->GetDes();
					_outFile << start << ',' << end;
					if (ArcList[y]->GetMode() == "Ship" || ArcList[y]->GetMode() == "Bus" || ArcList[y]->GetMode() == "Car" || ArcList[y]->GetMode() == "Rail" || ArcList[y]->GetMode() == "Bike")
					{

						_outFile << ',' << "PASS";
						_outFile << "\n";
					}
					else {
						y = ArcList.size() + 1;
						i = refs.size() + 1;
						_outFile << ',' << "FAIL";
					}
				}
				else if (refs[i + 1] == ArcList[y]->GetStart() && refs[i] == ArcList[y]->GetDes())
				{
					arcfound = true;
					int const start = ArcList[y]->GetDes();
					int const end = ArcList[y]->GetStart();
					_outFile << start << ',' << end;
					if (ArcList[y]->GetMode() == "Ship" || ArcList[y]->GetMode() == "Bus" || ArcList[y]->GetMode() == "Car" || ArcList[y]->GetMode() == "Rail" || ArcList[y]->GetMode() == "Bike")
					{

						_outFile << ',' << "PASS";
						_outFile << "\n";
					}
					else {
						y = ArcList.size() + 1;
						i = refs.size() + 1;
						_outFile << ',' << "FAIL";
					}
				}

			}
			if (arcfound == false)
			{
				int const start = refs[i];
				int const end = refs[i + 1];
				_outFile << start << ',' << end;
				_outFile << ',' << "FAIL";
				_outFile << "\n";
				i = refs.size() + 1;
				break;
			}


		}
		_outFile << "\n";

	}
	catch (const exception& exc)
	{
		return false;
	}
}

bool Navigation::ProcessCheckBus(vector<int>& refs)
{
	try
	{

		_outFile << "Check Bus ";
		for (int z = 0; z < refs.size(); z++)
		{
			_outFile << refs[z];
			_outFile << ' ';
		}
		_outFile << "\n";
		
		for (int i = 0; i < refs.size() -1; i++)
		{
			bool arcfound = false;
			
			for (int y = 0; y < ArcList.size(); y++)
			{
				
				if (refs[i] == ArcList[y]->GetStart() && refs[i + 1] == ArcList[y]->GetDes())
				{
					arcfound = true;
					int const start = ArcList[y]->GetStart();
					int const end = ArcList[y]->GetDes();
					_outFile << start << ',' << end;
					if (ArcList[y]->GetMode() == "Foot" || ArcList[y]->GetMode() == "Bike" || ArcList[y]->GetMode() == "Rail" || ArcList[y]->GetMode() == "Car")
					{
						
						_outFile << ',' << "FAIL";
						break;

					}
					else {
						_outFile << ',' << "PASS";
						_outFile << "\n";
					}
				}
				else if (refs[i + 1] == ArcList[y]->GetStart() && refs[i] == ArcList[y]->GetDes())
				{
					arcfound = true;
					int const start = refs[i];
					int const end = refs[i + 1];
					_outFile << start << ',' << end;
					if (ArcList[y]->GetMode() == "Bus" || ArcList[y]->GetMode() == "Ship")
					{

						_outFile << ',' << "PASS";
						_outFile << "\n";
					}
					else {
						_outFile << ',' << "FAIL";

						break;


					}
				}



				


			}
			if (arcfound == false)
			{
				int const start = refs[i];
				int const end = refs[i + 1];
				_outFile << start << ',' << end;
				_outFile << ',' << "FAIL";
				_outFile << "\n";
				i = refs.size() + 1;
				break;
			}


		}
		_outFile << "\n";

	}
	catch (const exception& exc)
	{
		return false;
	}
}

bool Navigation::ProcessFindRouteRail(const int ref1, const int ref2)
{
	try {
		int const NodeRef1 = ref1;
		int const NodeRefdes = ref2;
		int destination = 0;{}
		int x = -1;
		bool isequal = true;
		vector<int> refs;
		vector<int> vistednode;
		vistednode.push_back(NodeRef1);
		string const name = "FindRoute Rail ";
		if (_outFile.is_open()) {
			_outFile << name;
			_outFile << NodeRef1;
			_outFile << ' ';
			_outFile << NodeRefdes;
			_outFile << '\n';
		}
		while (isequal)
		{

			x++;
			if (vistednode.size() <= x)
			{
				isequal = false;
				break;

			}
			for (int i = 0; i < ArcList.size(); i++) {
				if (vistednode[x] == ArcList[i]->GetStart())
				{

					int const NodeRef2 = ArcList[i]->GetDes();
					refs.push_back(NodeRef2);

				}
				if (vistednode[x] == ArcList[i]->GetDes())
				{
					int const NodeRef2 = ArcList[i]->GetStart();
					refs.push_back(NodeRef2);

				}
			}
			for (int z = 0; z < refs.size() - 1; z++)
			{
				bool arcfound = false;

				for (int y = 0; y < ArcList.size(); y++)
				{
					if (refs[z] == ArcList[y]->GetStart() && vistednode[x] == ArcList[y]->GetDes())
					{
						arcfound = true;
						int const start = ArcList[y]->GetStart();
						if (ArcList[y]->GetMode() == "Rail")
						{
							vistednode.push_back(start);
						
						}

					}
					else if (vistednode[x] == ArcList[y]->GetStart() && refs[z] == ArcList[y]->GetDes())
					{
						arcfound = true;
						int const start = ArcList[y]->GetDes();
						if (ArcList[y]->GetMode() == "Rail")
						{

							vistednode.push_back(start);

						}
					}

				}
				if (arcfound == false)
				{
					z = refs.size() + 1;
					break;
				}
				if (NodeRefdes == vistednode[x])
				{
					destination = NodeRefdes;
					isequal = false;
					remove(vistednode);
					vistednode.pop_back();
					break;
				}
				if (vistednode.size() == 1000)
				{
					isequal = false;
					break;
				}

			}

			refs.clear();

		}
		for (int w = 0; w < vistednode.size(); w++)
		{
			if (vistednode.size() == 1000 || vistednode.size() <= 1)
			{
				_outFile << "FAIL";
				_outFile << "\n";
				goto stop;
				break;
			}
			_outFile << vistednode[w];
			_outFile << "\n";
		}
		stop:
		_outFile << "\n";

		vistednode.clear();
		refs.clear();
		return true;
	}
	catch (const exception& exc) {
		return false;
	}
}

bool Navigation::ProcessFindRouteShip(const int ref1, const int ref2)
{
	try {
		int const NodeRef1 = ref1;
		int const NodeRefdes = ref2;
		int destination = 0; {}
		int x = -1;
		bool isequal = true;
		vector<int> refs;
		vector<int> vistednode;
		vistednode.push_back(NodeRef1);
		string const name = "FindRoute Ship ";
		if (_outFile.is_open()) {
			_outFile << name;
			_outFile << NodeRef1;
			_outFile << ' ';
			_outFile << NodeRefdes;
			_outFile << '\n';
		}
		while (isequal)
		{

			x++;
			if (vistednode.size() <= x)
			{
				isequal = false;
				break;

			}
			for (int i = 0; i < ArcList.size(); i++) {
				if (vistednode[x] == ArcList[i]->GetStart())
				{

					int const NodeRef2 = ArcList[i]->GetDes();
					refs.push_back(NodeRef2);

				}
				if (vistednode[x] == ArcList[i]->GetDes())
				{
					int const NodeRef2 = ArcList[i]->GetStart();
					refs.push_back(NodeRef2);

				}
			}
			for (int z = 0; z < refs.size() - 1; z++)
			{
				bool arcfound = false;

				for (int y = 0; y < ArcList.size(); y++)
				{
					if (refs[z] == ArcList[y]->GetStart() && vistednode[x] == ArcList[y]->GetDes())
					{
						arcfound = true;
						int const start = ArcList[y]->GetStart();
						if (ArcList[y]->GetMode() == "Ship")
						{
							vistednode.push_back(start);

						}

					}
					else if (vistednode[x] == ArcList[y]->GetStart() && refs[z] == ArcList[y]->GetDes())
					{
						arcfound = true;
						int const start = ArcList[y]->GetDes();
						if (ArcList[y]->GetMode() == "Ship")
						{

							vistednode.push_back(start);

						}
					}

				}
				if (arcfound == false)
				{
					z = refs.size() + 1;
					break;
				}
				if (NodeRefdes == vistednode[x])
				{
					destination = NodeRefdes;
					isequal = false;
					remove(vistednode);
					vistednode.pop_back();
					break;
				}
				if (vistednode.size() == 1000)
				{
					isequal = false;
					break;
				}
			}
			refs.clear();
		}
		for (int w = 0; w < vistednode.size(); w++)
		{
			if (vistednode.size() == 1000 || vistednode.size() <= 1)
			{
				_outFile << "FAIL";
				_outFile << "\n";
				break;
			}
			_outFile << vistednode[w];
			_outFile << "\n";
		}

		_outFile << "\n";

		vistednode.clear();
		refs.clear();
		return true;
	}
	catch (const exception& exc) {
		return false;
	}
}

bool Navigation::ProcessFindRouteBus(const int ref1, const int ref2)
{
	try {
		int const NodeRef1 = ref1;
		int const NodeRefdes = ref2;
		int destination = 0; {}
		int x = -1;
		bool isequal = true;
		vector<int> refs;
		vector<int> vistednode;
		vistednode.push_back(NodeRef1);
		string const name = "FindRoute Bus ";
		if (_outFile.is_open()) {
			_outFile << name;
			_outFile << NodeRef1;
			_outFile << ' ';
			_outFile << NodeRefdes;
			_outFile << '\n';
		}
		while (isequal)
		{

			x++;
			if (vistednode.size() <= x)
			{
				isequal = false;
				break;

			}
			for (int i = 0; i < ArcList.size(); i++) {
				if (vistednode[x] == ArcList[i]->GetStart())
				{

					int const NodeRef2 = ArcList[i]->GetDes();
					refs.push_back(NodeRef2);

				}
				if (vistednode[x] == ArcList[i]->GetDes())
				{
					int const NodeRef2 = ArcList[i]->GetStart();
					refs.push_back(NodeRef2);

				}
			}
			for (int z = 0; z < refs.size() - 1; z++)
			{
				bool arcfound = false;

				for (int y = 0; y < ArcList.size(); y++)
				{
					if (refs[z] == ArcList[y]->GetStart() && vistednode[x] == ArcList[y]->GetDes())
					{
						arcfound = true;
						int const start = ArcList[y]->GetStart();
						if (ArcList[y]->GetMode() == "Bus" || ArcList[y]->GetMode() == "Ship")
						{
							vistednode.push_back(start);

						}

					}
					else if (vistednode[x] == ArcList[y]->GetStart() && refs[z] == ArcList[y]->GetDes())
					{
						arcfound = true;
						int const start = ArcList[y]->GetDes();
						if (ArcList[y]->GetMode() == "Bus" || ArcList[y]->GetMode() == "Ship")
						{

							vistednode.push_back(start);

						}
					}

				}
				if (arcfound == false)
				{
					z = refs.size() + 1;
					break;
				}
				if (NodeRefdes == vistednode[x])
				{
					destination = NodeRefdes;
					isequal = false;
					remove(vistednode);
					break;
				}
				if (vistednode.size() == 1000)
				{
					isequal = false;
					break;
				}

			}

			refs.clear();

		}
		for (int w = 0; w < vistednode.size(); w++)
		{
			if (vistednode.size() == 1000 || vistednode.size() <= 1)
			{
				_outFile << "FAIL";
				_outFile << "\n";
				goto stop;
				break;
			}
			_outFile << vistednode[w];
			_outFile << "\n";
		}
	stop:
		_outFile << "\n";

		vistednode.clear();
		refs.clear();
		return true;
	}
	catch (const exception& exc) {
		return false;
	}
}

bool Navigation::ProcessFindRouteCar(const int ref1, const int ref2)
{
	try {
		int const NodeRef1 = ref1;
		int const NodeRefdes = ref2;
		int destination = 0; {}
		int x = -1;
		bool isequal = true;
		vector<int> refs;
		vector<int> vistednode;
		vistednode.push_back(NodeRef1);
		string const name = "FindRoute Car ";
		if (_outFile.is_open()) {
			_outFile << name;
			_outFile << NodeRef1;
			_outFile << ' ';
			_outFile << NodeRefdes;
			_outFile << '\n';
		}
		while (isequal)
		{

			x++;
			if (vistednode.size() <= x)
			{
				isequal = false;
				break;

			}
			for (int i = 0; i < ArcList.size(); i++) {
				if (vistednode[x] == ArcList[i]->GetStart())
				{

					int const NodeRef2 = ArcList[i]->GetDes();
					refs.push_back(NodeRef2);

				}
				if (vistednode[x] == ArcList[i]->GetDes())
				{
					int const NodeRef2 = ArcList[i]->GetStart();
					refs.push_back(NodeRef2);

				}
			}
			for (int z = 0; z < refs.size() - 1; z++)
			{
				bool arcfound = false;

				for (int y = 0; y < ArcList.size(); y++)
				{
					if (refs[z] == ArcList[y]->GetStart() && vistednode[x] == ArcList[y]->GetDes())
					{
						arcfound = true;
						int const start = ArcList[y]->GetStart();
						if (ArcList[y]->GetMode() == "Ship" || ArcList[y]->GetMode() == "Bus" || ArcList[y]->GetMode() == "Car")
						{
							vistednode.push_back(start);

						}

					}
					else if (vistednode[x] == ArcList[y]->GetStart() && refs[z] == ArcList[y]->GetDes())
					{
						arcfound = true;
						int const start = ArcList[y]->GetDes();
						if (ArcList[y]->GetMode() == "Ship" || ArcList[y]->GetMode() == "Bus" || ArcList[y]->GetMode() == "Car")
						{

							vistednode.push_back(start);

						}
					}

				}
				if (arcfound == false)
				{
					z = refs.size() + 1;
					break;
				}
				if (NodeRefdes == vistednode[x])
				{
					destination = NodeRefdes;
					isequal = false;
					remove(vistednode);
					break;
				}
				if (vistednode.size() == 1000)
				{
					isequal = false;
					break;
				}

			}

			refs.clear();

		}
		for (int w = 0; w < vistednode.size(); w++)
		{
			if (vistednode.size() == 1000 || vistednode.size() <= 1)
			{
				_outFile << "FAIL";
				_outFile << "\n";
				goto stop;
				break;
			}
			_outFile << vistednode[w];
			_outFile << "\n";
		}
	stop:
		_outFile << "\n";

		vistednode.clear();
		refs.clear();
		return true;
	}
	catch (const exception& exc) {
		return false;
	}
}

bool Navigation::ProcessFindRouteBike(const int ref1, const int ref2)
{
	try {
		int const NodeRef1 = ref1;
		int const NodeRefdes = ref2;
		int destination = 0; {}
		int x = -1;
		bool isequal = true;
		vector<int> refs;
		vector<int> vistednode;
		vistednode.push_back(NodeRef1);
		string const name = "FindRoute Bike ";
		if (_outFile.is_open()) {
			_outFile << name;
			_outFile << NodeRef1;
			_outFile << ' ';
			_outFile << NodeRefdes;
			_outFile << '\n';
		}
		while (isequal)
		{

			x++;
			if (vistednode.size() <= x)
			{
				isequal = false;
				break;

			}
			for (int i = 0; i < ArcList.size(); i++) {
				if (vistednode[x] == ArcList[i]->GetStart())
				{

					int const NodeRef2 = ArcList[i]->GetDes();
					refs.push_back(NodeRef2);

				}
				if (vistednode[x] == ArcList[i]->GetDes())
				{
					int const NodeRef2 = ArcList[i]->GetStart();
					refs.push_back(NodeRef2);

				}
			}
			for (int z = 0; z < refs.size() - 1; z++)
			{
				bool arcfound = false;

				for (int y = 0; y < ArcList.size(); y++)
				{
					if (refs[z] == ArcList[y]->GetStart() && vistednode[x] == ArcList[y]->GetDes())
					{
						arcfound = true;
						int const start = ArcList[y]->GetStart();
						if (ArcList[y]->GetMode() == "Ship" || ArcList[y]->GetMode() == "Bus" || ArcList[y]->GetMode() == "Car" || ArcList[y]->GetMode() == "Rail")
						{
							vistednode.push_back(start);

						}

					}
					else if (vistednode[x] == ArcList[y]->GetStart() && refs[z] == ArcList[y]->GetDes())
					{
						arcfound = true;
						int const start = ArcList[y]->GetDes();
						if (ArcList[y]->GetMode() == "Ship" || ArcList[y]->GetMode() == "Bus" || ArcList[y]->GetMode() == "Car" || ArcList[y]->GetMode() == "Rail")
						{

							vistednode.push_back(start);

						}
					}

				}
				if (arcfound == false)
				{
					z = refs.size() + 1;
					break;
				}
				if (NodeRefdes == vistednode[x])
				{
					destination = NodeRefdes;
					isequal = false;
					remove(vistednode);
					break;
				}
				if (vistednode.size() == 1000)
				{
					isequal = false;
					break;
				}

			}

			refs.clear();

		}
		for (int w = 0; w < vistednode.size(); w++)
		{
			if (vistednode.size() == 1000 || vistednode.size() <= 1)
			{
				_outFile << "FAIL";
				_outFile << "\n";
				goto stop;
				break;
			}
			_outFile << vistednode[w];
			_outFile << "\n";
		}
	stop:
		_outFile << "\n";

		vistednode.clear();
		refs.clear();
		return true;
	}
	catch (const exception& exc) {
		return false;
	}
}

bool Navigation::ProcessFindRouteFoot(const int ref1, const int ref2)
{
	try {
		int const NodeRef1 = ref1;
		int const NodeRefdes = ref2;
		int destination = 0; {}
		int x = -1;
		bool isequal = true;
		vector<int> refs;
		vector<int> vistednode;
		vistednode.push_back(NodeRef1);
		string const name = "FindRoute Foot ";
		if (_outFile.is_open()) {
			_outFile << name;
			_outFile << NodeRef1;
			_outFile << ' ';
			_outFile << NodeRefdes;
			_outFile << '\n';
		}
		while (isequal)
		{

			x++;
			if (vistednode.size() <= x)
			{
				isequal = false;
				break;

			}
			for (int i = 0; i < ArcList.size(); i++) {
				if (vistednode[x] == ArcList[i]->GetStart())
				{

					int const NodeRef2 = ArcList[i]->GetDes();
					refs.push_back(NodeRef2);

				}
				if (vistednode[x] == ArcList[i]->GetDes())
				{
					int const NodeRef2 = ArcList[i]->GetStart();
					refs.push_back(NodeRef2);

				}
			}
			for (int z = 0; z < refs.size() - 1; z++)
			{
				bool arcfound = false;

				for (int y = 0; y < ArcList.size(); y++)
				{
					if (refs[z] == ArcList[y]->GetStart() && vistednode[x] == ArcList[y]->GetDes())
					{
						arcfound = true;
						int const start = ArcList[y]->GetStart();
						if (ArcList[y]->GetMode() == "Ship" || ArcList[y]->GetMode() == "Bus" || ArcList[y]->GetMode() == "Car" || ArcList[y]->GetMode() == "Rail" || ArcList[y]->GetMode() == "Bike")
						{
							vistednode.push_back(start);

						}

					}
					else if (vistednode[x] == ArcList[y]->GetStart() && refs[z] == ArcList[y]->GetDes())
					{
						arcfound = true;
						int const start = ArcList[y]->GetDes();
						if (ArcList[y]->GetMode() == "Ship" || ArcList[y]->GetMode() == "Bus" || ArcList[y]->GetMode() == "Car" || ArcList[y]->GetMode() == "Rail" || ArcList[y]->GetMode() == "Bike")
						{

							vistednode.push_back(start);

						}
					}

				}
				if (arcfound == false)
				{

					z = refs.size() + 1;
					break;
				}
				if (NodeRefdes == vistednode[x])
				{
					destination = NodeRefdes;
					isequal = false;
					remove(vistednode);
					break;
				}
				if (vistednode.size() == 1000)
				{
					isequal = false;
					break;
				}

			}

			refs.clear();

		}
		for (int w = 0; w < vistednode.size(); w++)
		{
			if (vistednode.size() == 1000 || vistednode.size() <= 1)
			{
				_outFile << "FAIL";
				_outFile << "\n";
				goto stop;
				break;
			}
			_outFile << vistednode[w];
			_outFile << "\n";
		}
	stop:
		_outFile << "\n";

		vistednode.clear();
		refs.clear();
		return true;
	}
	catch (const exception& exc) {
		return false;
	}
}



bool Navigation::BuildNetwork(const string& fileNamePlaces, const string& fileNameLinks)
{
	fstream  finPlaces(fileNamePlaces);
	fstream  finLinks(fileNameLinks);
	if (finPlaces.fail() || finLinks.fail()) return false;

	// ****** Add your code here *******

	vector<string> place;
	string tmp;
	int x1 = 0;

	while (getline(finPlaces, tmp, ',')) {
		place.push_back(tmp);

		x1++;
		if (x1 == 3) {
			getline(finPlaces, tmp, '\n');
			place.push_back(tmp);
			x1 = 0;
			double x, y;
			LLtoUTM(stod(place[2]), stod(place[3]), x, y);

			Node* const node = new Node(place[0], stoi(place[1]), x, y);
			nodelist.push_back(node);
			place.clear();
		}

	}

	vector<string> links;

	string tmp1;
	int x2 = 0;
	double dist;
	while (getline(finLinks, tmp1, ',')) {
		links.push_back(tmp1);

		x2++;
		if (x2 == 2) {
			getline(finLinks, tmp1, '\n');
			links.push_back(tmp1);
			x2 = 0;
			dist = calcDist(stoi(links[0]), stoi(links[1]));
			Arcs* const arc = new Arcs(stoi(links[0]), stoi(links[1]), links[2], dist);
			ArcList.push_back(arc);
			links.clear();
		}

	}





	return true;
}


Node* Navigation::FindNodes(const int a)
{
	for (int i = 0; i < nodelist.size(); i++)
	{
		if (nodelist[i]->GetRefNumber() == a)
		{
			Node* const x = nodelist[i];
			return x;
		}
	}

	return nullptr;
}

double Navigation::calcDist(const int a, const int b)
{
	const Node* const startNode = FindNodes(a);
	const Node* const endNode = FindNodes(b);

	double const distance = sqrt(pow(startNode->Getx() - endNode->Getx(), 2) + pow(startNode->Gety() - endNode->Gety(), 2));
	return distance;
}

void Navigation::remove(vector<int>& v)const
{
	auto end = v.end();
	for (auto it = v.begin(); it != end; ++it) {
		end = std::remove(it + 1, end, *it);
	}

	v.erase(end, v.end());
}