#pragma once
#include "sqlite3.h"
#include "Event.h"
#include <iostream>
#include <string>

using namespace std;

static const char* dir = ".\SchedulePlanner\DataBaseCalendar.db";

void createDBCal(const char* s);
void createTable(const char* s);
void update(const char* s);
void deleteRec(const char* s, int id);
void insert(const char* s, string name, string desc, string type, string day, string starth, string endh);
vector<Event> select(const char* s);
