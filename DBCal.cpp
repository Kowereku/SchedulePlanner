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
		"id	INTEGER UNIQUE,"
		"priority	INTEGER NOT NULL DEFAULT 0,"
		"name	TEXT NOT NULL,"
		"desc	TEXT,"
		"type	TEXT NOT NULL DEFAULT 'NORMAL',"
		"start	INTEGER NOT NULL,"
		"end	INTEGER,"
		"PRIMARY KEY(id));";


	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DBCal);

		char* messaggeError;
		exit = sqlite3_exec(DBCal, sql.c_str(), NULL, 0, &messaggeError);

		if (exit != SQLITE_OK)
		{
			cerr << "Nie dziala tabela :(" << endl;
			sqlite3_free(messaggeError);
		}
		else
			cout << "Dziala :DD" << endl;
		sqlite3_close(DBCal);
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}
}

void insert(const char* s)
{
	sqlite3* DBCal;
	char* messageError;

	int exit = sqlite3_open(s, &DBCal);

	string sql("INSERT INTO calevents (name, desc, type, start, end) VALUES ('Spotkanie', 'Zebranie Zarzadu', 'NORMAL', 1716962400, 1716968700);");

	exit = sqlite3_exec(DBCal, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK)
	{
		cerr << "Blad w dodawaniu" << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Dodano" << endl;
}

void select(const char* s)
{
	sqlite3* DBCal;

	int exit = sqlite3_open(s, &DBCal);

	string sql = "SELECT * FROM calevents;";

	sqlite3_exec(DBCal, sql.c_str(), callback, NULL, NULL);
}

static int callback(void* NotUsed, int argc, char** argv, char** azColName) // argc - argument counter, argv - argument value, azColName - name of columns in db
{
	for (int i = 0; i < argc; i++)
	{
		cout << azColName[i] << ": " << argv[i] << endl;
	}

	cout << endl;

	return 0;
}