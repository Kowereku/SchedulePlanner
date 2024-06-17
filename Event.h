#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Event
{
public:
	Event(int id, string n, string d, string day, string sh, string eh);
	int id;
	string name;
	string desc;
	string day;
	string starth;
	string endh;
};

