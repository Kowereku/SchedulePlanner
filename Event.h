#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Event
{
public:
	Event(string n, string d, string t, string day, string sh, string eh);
	string getName();
	string getDesc();
	string getType();
	string getDay();
	string getStartH();
	string getEndH();
private:
	string name;
	string desc;
	string type;
	string day;
	string starth;
	string endh;
};

