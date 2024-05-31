#include "DBCal.h"

void createDBCal(const char* s)
{
	sqlite3* DBCal;
	int exit = 0;

	exit = sqlite3_open(s, &DBCal);

	sqlite3_close(DBCal);

}

void createTable(const char* s)
{
	sqlite3* DBCal;

	string sql =
		"CREATE TABLE IF NOT EXISTS calevents ("
		"id         INTEGER PRIMARY KEY UNIQUE AUTOINCREMENT,"
		"priority   INTEGER NOT NULL DEFAULT 0,"
		"name		TEXT NOT NULL,"
		"desc		TEXT,"
		"type		TEXT NOT NULL DEFAULT 'NORMAL',"
		"start		INTEGER NOT NULL,"
		"end		INTEGER,);";

	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DBCal);

		char* messaggeError;
		exit = sqlite3_exec(DBCal, sql.c_str(), NULL, 0, &messaggeError);

		if (exit != SQLITE_OK)
		{
			cerr << " Error Create Table" << endl;
			sqlite3_free(messaggeError);
		}
		else
			cout << " Table created Successfully" << endl;
		sqlite3_close(DBCal);
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}


}
