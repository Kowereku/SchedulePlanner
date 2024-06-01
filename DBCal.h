#pragma once
#include "sqlite3.h"
#include <iostream>
#include <string>

using namespace std;

static const char* dir = ".\SchedulePlanner\DataBaseCalendar.db";

void createDBCal(const char* s);
void createTable(const char* s);
void insert(const char* s);
void select(const char* s);
static int callback(void* NotUsed, int argc, char** argv, char** azColName);
